#include "philo.h"

void    *place_philo(t_vars *vars, t_philo *philo)
{
    int i;

    i = 0;
    philo[i].left_fork = &vars->mutex[vars->number_of_philosphers - 1];
    while (i < vars->number_of_philosphers)
    {
        philo[i].right_fork = &vars->mutex[i];
        if (i)
            philo[i].left_fork = &vars->mutex[i - 1];
        i++;
    }
    return (0);
}
