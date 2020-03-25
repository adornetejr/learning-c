#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SOURCE_FILENAME src.txt
#define OUTPUT_FILENAME out.txt

#define LINE_MAX_LEN 500
#define TOKEN_MAX_LEN 50

enum toktype {
  UNKNOW,
  OPERATOR,
  NUMBER,
  IDENTIFIER,
  RESWORD,
  COMMOPEN,
  COMMCLOSE
};

struct token {
  char lex[TOKEN_MAX_LEN + 1];
  enum toktype type;
};

#define STR(s) _STR(s)
#define _STR(s) #s

struct token *get_tok(const char *cs, const char **lastc);

int main(int argc, char *argv[])
{
  FILE *src_fd;
  FILE *outp_fd;

  if ((src_fd = fopen(STR(SOURCE_FILENAME), "r")) == NULL ||
      (outp_fd = fopen(STR(OUTPUT_FILENAME), "w")) == NULL) {
    perror(argv[0]);
    return -1;
  }

  int line_num;
  char line[LINE_MAX_LEN];

  line_num = 0;
  while (fgets(line, sizeof line, src_fd) != NULL) {
    fprintf(outp_fd, "%d\n", ++line_num);

    struct token *tok;
    const char *tok_firstc_ptr, *tok_lastc_ptr;

    for (tok_firstc_ptr = line;
	 (tok = get_tok(tok_firstc_ptr, &tok_lastc_ptr)) != NULL;
	 tok_firstc_ptr = tok_lastc_ptr + 1) {
      if (tok->type == COMMOPEN) {
	const char *comm_open = tok_lastc_ptr;

	for (tok_firstc_ptr = tok_lastc_ptr + 1;
	     (tok = get_tok(tok_firstc_ptr, &tok_lastc_ptr)) != NULL &&
	       tok->type != COMMCLOSE;
	     tok_firstc_ptr = tok_lastc_ptr + 1)
	  ;

	const char *comm_close = tok_lastc_ptr;

	fprintf(outp_fd, "%17s: ", "comentario");

	while (comm_open <= comm_close)
	  fputc(*comm_open++, outp_fd);

	fputc('\n', outp_fd);
	continue;
      }

      const char *type_name;

      switch (tok->type) {
      case NUMBER:
	type_name = "numeral";
	break;
      case OPERATOR:
	type_name = "operador";
	break;
      case IDENTIFIER:
	type_name = "identificador";
	break;
      case RESWORD:
	type_name = "palavra reservada";
	break;
      case UNKNOW:
      default:
	type_name = "desconhecido";
	break;
      }

      fprintf(outp_fd, "%17s: %s\n", type_name, tok->lex);
    }
  }

  exit(EXIT_SUCCESS);
}

int get_lex(char *lex, size_t lex_maxlen, const char *cs);
enum toktype get_toktype(const char *lex);

struct token *get_tok(const char *cs, const char **lastc)
{
  if (cs == NULL || lastc == NULL)
    return NULL;
  
  char tmp_lex[TOKEN_MAX_LEN + 1];
  int ccnt; /* Contador de caracteres lidos pelo scanner. */
  if ((ccnt = get_lex(tmp_lex, sizeof tmp_lex, cs)) == 0) {
    *lastc = cs;

    return NULL;
  } else if (tmp_lex[0] == '\0') {
    *lastc = &cs[ccnt - 1];

    return NULL;
  }

  *lastc = &cs[ccnt - 1];

  struct token *tok;
  if ((tok = malloc(sizeof(struct token))) == NULL) {
    perror("gettok()");
    exit(EXIT_FAILURE);
  }

  strncpy(tok->lex, tmp_lex, sizeof tmp_lex);
  tok->type = get_toktype(tok->lex);
  return tok;
}  

int get_lex(char *lex, size_t lex_maxlen, const char *cs)
{
  if (lex == NULL || lex_maxlen < 1 || cs == NULL || cs[0] == '\0')
    return 0;

  const char *strp = cs; /* Aponta para o proximo caracter da string fonte. */

  while (isspace(lex[0] = *strp++)) /* Espaco em branco nao eh relevante. */
    ;

  /*
    Se a string nao possui lexemas, devemos retornar uma string nula, pois o
    contador de caracteres nao pode ser usado para determinar tal informacao.
  */
  if (lex[0] == '\0')
    return strp - cs;

  /*
    A partir desse ponto a string possui um lexema. Iniciarei a busca do
    lexema supondo que ele eh um numeral.
  */
  char *lexp = &lex[1]; /* aponta para o proximo caracter do lexema. */

  if (isdigit(lex[0]) || lex[0] == '.' && isdigit(*strp))
    while (lexp - lex < lex_maxlen && (isdigit(*strp) || *strp == '.'))
      *lexp++ = *strp++;
  /* 
     Ate aqui nenhum caracter serviu na busca por um numeral entao procuraremos
     por caracteres compativeis com palavras reservadas ou identificadores.
  */
  else if (isalpha(lex[0]) || lex[0] == '_')
    while (lexp - lex < lex_maxlen && (isalnum(*strp) || *strp == '_'))
      *lexp++ = *strp++;
  /*
    Ainda nao sendo adequado so me resta supor que seja um operador. ispunct()
    procura por caracteres imprimiveis que nao sao nem espaco nem alfanumericos,
    justamente os adequados para tal.
  */
  else if (ispunct(lex[0]))
    while (lexp - lex < lex_maxlen && ispunct(*strp))
      *lexp++ = *strp++;

  *lexp = '\0';
  return strp - cs;
}  

int is_numeral(const char *lex);
int is_operator(const char *lex);
int is_resword(const char *lex);
int is_identifier(const char *lex);
int is_commet_open(const char *lex);
int is_commet_close(const char *lex);

enum toktype get_toktype(const char *lex)
{
  if (is_numeral(lex))
    return NUMBER;
  if (is_operator(lex))
    return OPERATOR;
  if (is_resword(lex))
    return RESWORD;
  if (is_identifier(lex))
    return IDENTIFIER;
  if (is_commopen(lex))
    return COMMOPEN;
  if (is_commclose(lex))
    return COMMCLOSE;

  return UNKNOW;
}

int is_commopen(const char *lex)
{
  if (lex == NULL)
    return 0;

  if (strcmp(lex, "{") == 0)
    return 1;

  return 0;
}

int is_commclose(const char *lex)
{
  if (lex == NULL)
    return 0;

  if (strcmp(lex, "}") == 0)
    return 1;

  return 0;
}

int is_numeral(const char *lex)
{
  if (lex == NULL)
    return 0;

  if (isdigit(*lex))
    while (isdigit(*++lex))
      ;
  
  if (*lex == '.')
    while (isdigit(*++lex))
      ;
  
  if (*lex == '\0')
    return 1;
  
  return 0;
}

int is_operator(const char *lex)
{
  const char *l_opers[] = {
    "+", "-",
    "*", "/",  
    "<>", "=", ">", "<", ">=", "<=",
    ":=",
    ";"
  };

  if (lex != NULL) {
    int i;

    for (i = 0; i < sizeof l_opers / sizeof(const char *); i++)
      if (strcmp(lex, l_opers[i]) == 0)
	return 1;
  }

  return 0;
}

int is_resword(const char *lex)
{
  const char *l_reswords[] = {
    "read", "write",
    "begin", "end",
    "if", "else", "then",
    "for", "while", "do", "until", "repeat"
  };

  if (lex != NULL && isalpha(*lex)) {
    int i;

    for (i = 0; i < sizeof l_reswords / sizeof(const char *); i++)
      if (strcmp(lex, l_reswords[i]) == 0)
	return 1;
  }

  return 0;
}

int is_identifier(const char *lex)
{
  if (lex != NULL && (isalpha(lex[0]) || lex[0] == '_' && isalpha(lex[1])))
    if (!is_resword(lex)) {
      while (isalnum(*++lex))
	;

      if (*lex == '\0')
	return 1;
    }

  return 0;
}