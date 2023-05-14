/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:37:16 by taelkhal          #+#    #+#             */
/*   Updated: 2023/05/04 16:29:26 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int test = 0;
void    *create_thread()
{
    int i;

    i = 0;
    while (i < 100)
    {
        test++;
        i++;
    }
}

int main(int ac, char **av)
{
    int a = ac - 1;
    pthread_t p[a];
    int i;

    i = 0;
    if (ac == 2)
    {
        while (i < a)
        {
            pthread_create(&p[a], NULL, &create_thread, NULL);
            pthread_join(p[a], NULL);
            i++;
        }
        printf ("%d", test);
    }
}
