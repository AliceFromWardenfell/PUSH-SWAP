#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 1
# define B 0

# define SA "sa\n" // ??
# define SB	"sb\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RRA "rra\n"
# define RRB "rrb\n"

# include "libft/libft.h"

# include <stdio.h> //remove

typedef	struct		s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_technical
{
	int				a_num;
	int				b_num;
	char			*instructions;
}					t_technical;

t_stack	*create_node(int val);
void	addnode_front(t_stack **lst, t_stack *new);
void	addnode_back(t_stack **lst, t_stack *new);
void	print_list(t_stack *a, t_technical *t, int flag); // remove
void	print_ab(t_stack *a, t_stack *b, t_technical *t); // remove
int		error(void);
int		check_argv(t_stack *a, char *str);
void	swap(t_stack **a, t_technical *t, int stack);
void	push(t_stack **a, t_stack **b, t_technical *t, int stack);
void	rotate(t_stack **a, t_technical *t, int stack);
void	r_rotate(t_stack **a, t_technical *t, int stack);
void	alg1(t_stack **a, t_stack **b, t_technical *t); // perhaps tmp
void	clean(t_stack **a, t_stack **b, t_technical *t);

#endif