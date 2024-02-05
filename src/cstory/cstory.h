#ifndef __CSTORY_H
#define __CSTORY_H

#if _CRAFT == __EC_CSTORY

#include <ecraft.h>

int64_t ec_start(char *title, char *subtitle, char *description);

elem_t *ec_elem(char *dname, char *fname, char *lname);

int64_t ec_load(elem_t *elem, char *emoji, char *string);
int64_t ec_pull(elem_t *elem, char *emoji, char *string, int64_t ref);
void ec_final(void);
/*
 * int64_t ec_pack(elem_t **elemp, elem_t *elem, char *emoji);
 * int64_t ec_pop(elem_t **elemp, int64_t ref);
*/

/* library only function prototypes */
int64_t __ec_load(elem_t **elem, char **emoji, char *string);
int64_t __ec_load_1(ecraft_t **ecraft, elem_t *elem, char *emoji,
	char *string);
void __ec_load_2(ecraft_t **ecraft, char *string);
void __ec_read(int ref);
void __ec_exec(char *cmd);
void __add_elem(elem_t *elem);
void __delem(void);
void __decraft(int64_t index);
void __ec_mvprint(const char *type, char *str, int x, int y);
void __ec_emoji(char *emoji, int64_t index);
void __pemoji(emoji_t emoji);
void __ec_head(void);
void __ec_head_cli(void);
void __ec_final(void);
void __key_up(void);

#endif	/* _CRAFT */

#endif	/* __CSTORY_H */
