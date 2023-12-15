#include <stdlib.h>
#include <string.h>
#include <term.h>
#include <termbox.h>

#include "ecraft.h"

__ECRAFT;

__EC_CLI;
__EC_GUI;

/**
 * ec_free - clean-up
 *	       this function must be called at the end of the user's program
 *	       in order to clean up or free all allocated blocks of  memory
 *
 * Return: return nothing
*/

void ec_free(void)
{
	int i = 0, interface;

	if (__ecraft == NULL)
		return;

	while (__ecraft[i] != NULL)
	{
		interface = __ecraft[i]->__interface;

		__c_del_cstory(__ecraft[i]->__cast);
		__m_del_cstory(__ecraft[i]->__meta);
		if (interface == EC_CLI)
			delscreen(__ecraft[i]->__interf.cli);
		else if (interface == EC_GUI)
		{
			/* delete gui window */
		}
		__free_craft(__ecraft[i]);
		i++;
	}
	free(__ecraft);
	if (__cli == EC_CLI)
	{
		endwin(), del_curterm(cur_term);
		delwin(stdscr), delwin(curscr), delwin(newscr);
		/*
		 * this is by far the best clean up for ncurses I know of
		 * any help on improving or making the ncurses clean up perfect
		 * is highly appreciated
		*/
		tb_shutdown();
	}
	if (__gui == EC_GUI)
	{
		/* end gui */
	}
	__cli = __EC_INIT, __gui = __EC_INIT;
}

/**
 * __free_craft - frees memory associated with a given craft
 *
 * @craft: pointer to the given craft
 *
 * Return: return nothing
*/

void __free_craft(ecraft_t *craft)
{
	if (craft == NULL)
		return;

	__free_cstory(craft);
}
