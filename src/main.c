#include "../cub.h"

int world_map[9][18] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int	main(int ac, char **av)
{
	(void)av;
	t_param	param;
	/* Pseudo code
	1. parsing the map(.cub file) -> if success, go to step 2. else, print error message "Error\n" and exit the program
	2. initialize the parameters
	3. draw the map
	4. handle the events
	5. close the window (free the allocated memory)

	structure of the program : 3 loops
	 - first loop: mlx-loop
	 - second loop: from x = 0 to x = width
	 - third loop: while (!hit)
	*/
	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	if (check_extension(av[1]) < 0)
		ft_error("file must finish by .cub");
	param.fd = check_openable(av[1]);
	if (param.fd < 0)
		ft_error("file is not openable");
	init_param(&param);
	//check each line and send information to param
	//check the map
	cast_rays_and_render(&param);
	event_handler(&param);
	mlx_loop(param.mlx);
	return (0);
}
