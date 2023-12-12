/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:11:39 by mbentahi          #+#    #+#             */
/*   Updated: 2023/12/12 21:37:23 by mbentahi         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55555
# endif

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr(const char *str, int c);
char *get_next_line(int fd);
char *ft_buffer_reader(char *str , int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif