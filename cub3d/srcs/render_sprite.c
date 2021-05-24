/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:09:23 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 22:33:41 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void    render_sprite(t_set *set, t_player *player, t_ray *ray, t_sprite *sprite)
{
    float       ang_sprite;
    float       epsilon;
    int         i;
    int         j;

    i = 0;
    while (i < set->sprite_num)
    {
        ang_sprite = normalize_ang(player->rot_ang) - atan2(sprite[i].y - player->y, sprite[i].x - player->x);
        if (ang_sprite > M_PI)
            ang_sprite -= M_PI * 2;
        if (ang_sprite < -M_PI)
            ang_sprite += M_PI * 2;
        ang_sprite = fabs(ang_sprite);
        epsilon = 0.2;
        if (ang_sprite < (set->fov / 2) + epsilon)
        {
            sprite[i].visible = 1;
            sprite[i].ang = ang_sprite;
            sprite[i].distance = distance_between_point(sprite[i].x, sprite[i].y, player->x, player->y);
        }
        else
            sprite[i].visible = 0;
        i++;
    }
    
    i = 0;
    while (i < set->sprite_num)
    {
        if (sprite[i].visible == 1)
        {
            j = i + 1;
            while (j < set->sprite_num)
            {
                if (sprite[j].visible == 1 &&  sprite[j].distance > sprite[i].distance)
                {
                    t_sprite temp;

                    temp = sprite[i];
                    sprite[i] = sprite[j];
                    sprite[j] = temp;
                }
                j++;
            }
        }
        i++;
    }

    i = 0;
    while (i < set->sprite_num)
    {
        float       perp;
        float       height;
        float       width;
        float       top;
        float       bot;
        float       ang;
        float       pos;
        float       left;
        float       right;
        int         x;
        int         y;

        if (sprite[i].visible == 1)
        {
            perp = sprite[i].distance * cos(sprite[i].ang);
            height = (GRID_SIZE / perp) * ((set->win_x / 2) / tan(set->fov / 2));
            width = height;
            top = set->win_y / 2 - height / 2;
            top = top < 0 ? 0 : top;
            bot = set->win_y / 2 + height / 2;
            bot = bot > set->win_y ? set->win_y : bot;
            ang = atan2(sprite[i].y - player->y, sprite[i].x - player->x) - player->rot_ang;
            pos = tan(ang) * ((set->win_x / 2) / tan(set->fov / 2));
            left = (set->win_x / 2) + pos - (width / 2);
            right = left + width;
            x = left - 1;
            while (x < right)
            {
                float   tex_width = (TEX_WIDTH / width);
                int     tex_x = (x - left) * tex_width;
                y = top - 1;
                while (y < bot)
                {
                    if (x > 0 && x < set->win_x && y > 0 && y < set->win_y)
                    {
                        int     dis_top = y + (height / 2) - (set->win_y / 2);
                        int     tex_y = dis_top * (TEX_HEIGHT / height);
                        int     color;

                        color = set->tex[4][(TEX_WIDTH * tex_y) + tex_x];
                        if (sprite[i].distance < ray[x].distance && color != 0x000000)
                            set->img.data[(set->win_x * y) + x] = color;
                    }
                    y++;
                }
                x++;
            }
        }
        i++;
    }
}