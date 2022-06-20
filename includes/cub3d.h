/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:27:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/20 03:44:24 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <../minilibx_macos/mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define MINLEN_ARG				5
# define ARG_NUM_ERROR			"Error\nNeed exactly one '.cub' parameter"
# define INVALID_ARG_ERROR		"Error\nArgument does not have '.cub' extension"
# define FILE_ERROR				"Error\nFile can't be opened or doesn't exist"
# define FILE_EMPTY_ERROR		"Error\nFile empty"
# define MALLOC_ERROR 			"Error\nMalloc failed"
# define INVALID_DATA_ERROR 	"Error\nInvalid data"
# define INVALID_RGB_ERROR 		"Error\nInvalid RGB data"
# define DUPLICATED_ENTRY_ERROR "Error\nMultiple entries for same identifier"
# define MISSING_DATA_ERROR		"Error\nMissing or invalid data in file"
# define AFTER_PATH_ERROR		"Error\nInvalid data after path"
# define NO_SPACE_ENTRY_ERROR	"Error\nNeed at least one space after identifier"
# define IDENTIFIER_PATH_ERROR	"Error\nInvalid data between identifier and path"
# define INVALID_MAP_ERROR		"Error\nInvalid map"
# define MULTIPLE_SPAWN_ERROR	"Error\nMultiple spawn locations found"
# define SPAWN_ERROR			"Error\nInvalid spawn location"
# define NO_SPAWN_ERROR			"Error\nNo spawn found"
# define MAP_OPEN_ERROR			"Error\nMap is not closed"
# define DR 0.0174533
# define W 1280
# define H 720

typedef struct s_map
{
	int		height;
	int		width;
	int		**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		start_posx;
	int		start_posy;
	char	orientation;
}	t_map;

typedef struct s_minimap
{
	int		length;
	int		width;
	int		height;
	int		tile_size;
	int		p_size;
	int		color;
}				t_minimap;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				w;
	int				h;
	int				bpp;
	int				lb;
	int				endian;
	struct s_data	*data;
}				t_img;

typedef struct s_raycast
{
	int		found;
	int		step_x;
	int		step_y;
	int		side;
	int		r;
	float	raymap_x;
	float	raymap_y;
	float	ray_step_x;
	float	ray_step_y;
	float	raystart_x;
	float	raystart_y;
	float	lenght_x;
	float	lenght_y;
	float	maxdistance;
	float	ra;
	float	rpa;
	float	dirx;
	float	diry;
	float	walldist;
	float	tick;
}				t_raycast;

typedef struct s_data
{
	int					**map;
	int					height;
	int					width;
	int					tile_size;
	char				*name;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_bytes;
	int					endian;
	void				*mlx;
	void				*win;
	float				px;
	float				py;
	float				old_x;
	float				old_y;
	float				pa;
	float				rot;
	float				pdx;
	float				pdy;
	float				interx;
	float				intery;
	float				current_x;
	float				current_y;
	float				next_x;
	float				next_y;
	float				tile_x;
	float				tile_y;
	int					step_x;
	int					step_y;
	float				raylen;
	float				draw_start;
	float				draw_end;
	int					color;
	float				w;
	float				s;
	float				a;
	float				d;
	float				l;
	float				r;
	t_map				*map_data;
	t_img				north;
	t_img				south;
	t_img				west;
	t_img				east;
	struct s_minimap	minimap;
	struct s_main		*main;
}				t_data;
typedef struct s_main
{
	t_map	*map;
	char	**raw_map;
}	t_main;

/** GET_FILE_INFO.C **/
void	basic_check_arg(char const *path, t_main *data);
void	get_map_info(char const *path, t_main *data);
char	*retrieve_info(char **tab, char const *target, t_main *data);
void	get_info(t_main *data);

/** CHECK_FILE_INFO.C  **/
int		check_line(char const *str, int c);
void	deep_check_info(char **tab, t_main *data);

/** PARSING_MAP.C  **/
void	find_map(t_main *data);
void	check_map(t_main *data, char **tab);
void	convert_map(t_main *data);
void	check_map_closed(int **tab, t_main *data);

/** PARSING_UTILS.C  **/
char	*skip_spaces(char const *str, char const *target);
int		get_map_width(char **tab);
void	fill_with_space(int *tab, int size);
void	skip_empty_lines(t_main *data, int *index);

/** LAUNCH.C  **/
int		launch(t_data *data);

/** KEYHOOK.C  **/
int		key_hook(t_data *data);
int		key_hook_press(int keycode, t_data *data);
int		key_hook_release(int keycode, t_data *data);

/** KEYHOOK.C  **/
void	go_forward(t_data *data);
void	go_backward(t_data *data);
void	go_right(t_data *data);
void	go_left(t_data *data);
void	rotate(t_data *data);

/** DEGTORAD.C  **/
float	degtorad(float a);

/** FIXANG.C  **/
float	fixang(float a);

/** DRAW_MAP.C  **/
void	draw_map(t_data *data);

/** DRAW_CUBE.C  **/
void	draw_cube(float current_x, float current_y,
			int size, t_data *data);

/** DRAW3DRAYS.C  **/
void	raycast(t_data *data);

/** DRAW_FRAME.C  **/
void	vertline(int x, int side, t_data *data, t_img *img);
void	draw_frame(t_data *data, t_raycast *raycast);

/** PUT_PIXEL.C  **/
void	put_pixel(int x, int y, int color, t_data *data);

/** GETPIX.C  **/
int		getpix(int x, int y, t_img *img);

/** FREE.C  **/
int		end(t_data *data);
void	close_program(char const *msg, t_main *ptr);
void	*free_map(t_map *ptr);

#endif
