/*
 *	
 */

#define		QUEUE_TYPE	int	/**/

/*
 *
 */
void create_queue(unsigned int size);

/*
 *
 */
void destroy_queue(void);

/*
 *	insert
 */
void insert(QUEUE_TYPE value);

/*
 *	first
 */
QUEUE_TYPE first(void);

/*
 *	is_empty
 */
int is_empty(void);

/*
 *	is_full
 */
int is_full(void);
