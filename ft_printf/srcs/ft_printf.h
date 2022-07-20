/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguan-xi <lguan-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:38:45 by lguan-xi          #+#    #+#             */
/*   Updated: 2022/07/20 16:39:17 by lguan-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h" 
# include <stdarg.h>   //variadic function
# include <unistd.h>  //write
# include <stdlib.h> //malloc

int		ft_putnum(int n); //%d, %i
int		ft_get_len(unsigned int num);

int		ft_putchar(char c); //%c
int		ft_putstr(char *str); //%s 
int		print_percent(void); //%

//%u
int		ft_get_ulen(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_putunum(unsigned int num);

//%x %X
int		ft_hexa_len(unsigned int n);
int		ft_puthexa(unsigned int hexa, char *str);

//%p
int		ft_hexa_ptr(uintptr_t hexa);
void	ft_puthexaptr(uintptr_t hexa, char *str);
int		ft_returnptr(uintptr_t ptr, char *str);

int		check_format(va_list ap, const char type);
int		ft_printf(const char *str, ...);

#endif
