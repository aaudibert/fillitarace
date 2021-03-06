/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:28:16 by jumiguel          #+#    #+#             */
/*   Updated: 2016/11/20 17:00:13 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_init(t_struct *global)
{
	global->i = 0;
	global->nbrhash = 0;
	global->counti = 0;
	global->y = 0;
	global->col = 0;
	global->power = 0;
	global->mapopti = 0;
	global->c = 'A';
	global->ctetro = 0;
}

int		main(int ac, char **av)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE];
	t_struct	*global;

	if (ac != 2)
		return (ft_error(1));
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_error(2));
		if ((ret = read(fd, buf, BUFF_SIZE)) > 545)
			return (ft_error(3));
		buf[ret] = '\0';
		if ((global = (t_struct *)malloc(sizeof(t_struct))) == NULL)
			return (ft_error(4));
		if (ft_tetrosvalid(buf, global) != 0)
			return (ft_error(5));
		if (ft_resolve(global) != 0)
			return (ft_error(6));
		if (close(fd) == -1)
			return (ft_error(4));
	}
	return (0);
}
