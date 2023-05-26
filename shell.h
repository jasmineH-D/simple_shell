#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>



#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1



#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3



#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2



#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: num field
 * @str: string
 * @next: points to the next node
 */


typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 *struct passinfo - contains fictitious arguments used to call functions,
 *allowing a consistent prototype for function pointer structs.
 *@arg: a string produced by getline that contains arguments
 *@argv: a collection of strings created from arg
 *@path: a string representing the current command's path
 *@argc: argument count
 *@line_count: the number of errors
 *@err_num: the exit() error code
 *@linecount_flag: if this line of input counts,
 *@fname: program filename
 *@env: localised linked list copy of environ
 *@environ: LL env environment modified specifically
 *@history: historical node
 *@alias: alias node
 *@env_changed: if the environment had changed.
 *@status: the last command that was executed's return status
 *@cmd_buf: address of the cmd_buf pointer, if chaining
 *@cmd_buf_type: Command-type ||, &&, ;
 *@readfd: the fd to read line input from
 *@histcount: the number of lines in history
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} biltin_tale;




int hsh(info_t *, char **);
int findloc_builtinco(info_t *);
void find_command(info_t *);
void fork_command(info_t *);



int is_comdd(info_t *, char *);
char *da_ch(char *, int, int);
char *fed_putt(info_t *, char *, char *);



int loophsh(char **);



void _eppu(char *);
int _epitch(char);
int _puiuf(char c, int fd);
int _puqsd(char *str, int fd);



int _stles(char *);
int _stcmm(char *, char *);
char *stres_wi(const char *, const char *);
char *_stcet(char *, char *);



char *_stcop(char *, char *);
char *_strtpp(const char *);
void _puuss(char *);
int _puuchi(char);



char *_cpsrting(char *, char *, int);
char *_copncatsr(char *, char *, int);
char *_fidchr(char *, char);



char **sttiww(char *, char *);
char **sttiw2(char *, char);



char *_memfill(char *, char, unsigned int);
void ffrre(char **);
void *_reeloc(void *, unsigned int, unsigned int);



int frnpr(void **);



int active(info_t *);
int ist_de(char, char *);
int _isph(int);
int _atii(char *);



int _strtoint(char *);
void print_errorms(info_t *, char *);
int print_dec(int, int);
char *convert_snum(long int, int, int);
void replace_comments(char *);




int _miex(info_t *);
int _micedd(info_t *);
int _mihely(info_t *);




int _myhist(info_t *);
int _myhelpalias(info_t *);



ssize_t gets_inp(info_t *);
int _geli(info_t *, char **, size_t *);
void sigHan(int);



void cledel_inf(info_t *);
void sett_inf(info_t *, char **);
void fr_inf(info_t *, int);


char *_geevv(info_t *, const char *);
int _mievv(info_t *);
int _miserevv(info_t *);
int _miunsotevv(info_t *);
int populate_evv_li(info_t *);



char **cp_evviron_str(info_t *);
int _rmunsetenv(info_t *, char *);
int _initenva(info_t *, char *, char *);



char *get_histret_fi(info_t *info);
int writecre_apphistory(info_t *info);
int red_hist(info_t *info);
int bud_addhs_ls(info_t *info, char *buf, int linecount);
int rem_his(info_t *info);



list_t *adn_nod(list_t **, const char *, int);
list_t *adn_no_ed(list_t **, const char *, int);
size_t prin_li_st(const list_t *);
int rm_nod_a_ind(list_t **, unsigned int);
void frre_lis(list_t **);




size_t lis_lens(const list_t *);
char **liis_t_str(list_t *);
size_t prii_liss(const list_t *);
list_t *nodd_st_wi(list_t *, char *, char);
ssize_t gett_nodd_in(list_t *, list_t *);



int is_chain(info_t *, char *, size_t *);
void cheok_cha(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
