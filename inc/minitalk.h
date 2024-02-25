/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:58:09 by nlence-l          #+#    #+#             */
/*   Updated: 2024/02/25 12:58:11 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
