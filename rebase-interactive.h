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

enum edit_todo_result {
	EDIT_TODO_OK = 0,         // must be 0
	EDIT_TODO_IOERROR = -1,   // generic i/o error; must be -1
	EDIT_TODO_FAILED = -2,    // editing failed
	EDIT_TODO_ABORT = -3,     // user requested abort
	EDIT_TODO_INCORRECT = -4  // file violates syntax or constraints
};

void append_todo_help(int command_count, enum rebase_action action,
		      const char *shortrevisions, const char *shortonto,
		      struct strbuf *buf);
enum edit_todo_result edit_todo_list(
		   struct repository *r, struct todo_list *todo_list,
		   struct todo_list *new_todo, const char *shortrevisions,
		   const char *shortonto, unsigned flags,
		   enum rebase_action action);

int todo_list_check(struct todo_list *old_todo, struct todo_list *new_todo);
int todo_list_check_against_backup(struct repository *r,
				   struct todo_list *todo_list);

#endif
