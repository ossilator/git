#ifndef REBASE_INTERACTIVE_H
#define REBASE_INTERACTIVE_H

struct strbuf;
struct repository;
struct todo_list;

enum rebase_action {
	ACTION_NONE = 0,
	ACTION_CONTINUE,
	ACTION_SKIP,
	ACTION_ABORT,
	ACTION_QUIT,
	ACTION_EDIT_TODO,
	ACTION_SHOW_CURRENT_PATCH,
	ACTION_LAST
};

void append_todo_help(int command_count, enum rebase_action action,
		      const char *shortrevisions, const char *shortonto,
		      struct strbuf *buf);
int edit_todo_list(struct repository *r, struct todo_list *todo_list,
		   struct todo_list *new_todo, const char *shortrevisions,
		   const char *shortonto, unsigned flags,
		   enum rebase_action action);

int todo_list_check(struct todo_list *old_todo, struct todo_list *new_todo);
int todo_list_check_against_backup(struct repository *r,
				   struct todo_list *todo_list);

#endif
