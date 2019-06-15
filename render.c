/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:12:24 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/15 21:19:13 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf.h"
#include <stdio.h>
#include "mlx.h"


static int		colors(t_win *cr, int i, double column)
{
	int tx;
	double	ty;
	double	x;
	int t;
	int c;


	if (cr->wall == 'n')
		cr->objcl = 0xff0000;
	else if (cr->wall == 's')
		cr->objcl = 0x00ff00;
	else if (cr->wall == 'w')
		cr->objcl = 0x0000ff;
	else if (cr->wall == 'e')
		cr->objcl = 0x0f0f0f;
//
	if (cr->wall == 'n' || cr->wall == 's')
		x = cr->hitx;
	else
		x = cr->hity;
	tx = (x - (int)x) * TEXSIZE;
	ty = (double)TEXSIZE / column;
	// printf("%d %d | ", cr->hitx, cr->hity);
	t = i * ty;
	c = cr->addrtext[tx + (t * TEXSIZE)];
		// return (c);
		return (cr->objcl);
}

void	draw(t_win *cr, int ray)
{
	int i;
	double	column;
	double	beg;

	i = 0;
	column = WIN_HIGHT / cr->dist / 10;
	beg = (WIN_HIGHT - column) / 2;
	// printf("%d\n    ", ray);
	while (i < WIN_HIGHT)
	{
		if ((i > beg) && (i < WIN_HIGHT - beg) && i > 0)
		{
			cr->wall = checker(cr->hitx, cr->hity, cr->tiles);
			// cr->wall = 's';
			if (cr->wall == 'e')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
			if (cr->wall == 'n')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
			if (cr->wall == 's')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
			if (cr->wall == 'w')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
		}
		i++;
	}
}