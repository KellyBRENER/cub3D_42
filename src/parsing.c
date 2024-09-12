#include "../cub.h"

bool	load_texture(t_param *param)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		param->tex[i].img = mlx_xpm_file_to_image(param->mlx, \
			param->tex[i].path, &param->tex[i].w, &param->tex[i].h);
		if (!param->tex[i].img)
		{
			printf("Error: Unable to load t from %s\n", param->tex[i].path);
			return (false);
		}
		param->tex[i].addr = mlx_get_data_addr(param->tex[i].img, \
			&param->tex[i].bits_per_pixel, &param->tex[i].size_line, \
			&param->tex[i].endian);
		i++;
	}
	return (true);
}

int	check_extension(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4)
		return (-1);
	if (ft_strcmp(av + (len - 4), ".cub") =! 0)
		return (-1);
}

int	check_openable(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	return (fd);
}
