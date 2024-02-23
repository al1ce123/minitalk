#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/inc/libft.h"

void	ft_handler(int signal, siginfo_t *info, void *s);
void	ft_sender(int pid, char c);
int		ft_atoi(char *str);
char	*add_c_to_str(char *str, char c);
char	*print_and_free(char *str);

#endif
