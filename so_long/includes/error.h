/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:24:46 by fwu               #+#    #+#             */
/*   Updated: 2024/10/22 18:36:09 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_NUM -1

// ERROR MESSAGE
# define MSG_ARGC_ERR "you should input a name of the map"

# define MSG_EMPTY_LINE_ERR "empty line found in map"
# define MSG_EMPTY_MAP_ERR "map is empty"
# define MSG_READ_FILE_ERR "read file fail"
# define MSG_CLOSE_FILE_ERR "close file fail"

# define MSG_MAP_NOT_RECTANGULAR  "map is not rectangular"
# define MSG_EDGE_IS_NOT_WALL "edge is not wall"
# define MSG_COIN_NUM_ERR  "coin number error"
# define MSG_EXIT_NUM_ERR  "exit number error"
# define MSG_PLAYER_NUM_ERR  "player number error"
# define MSG_CHARACTER_NOT_FOUND "character not found"

# define MSG_PARENT_MALLOC_ERR "parent malloc fail"
# define MSG_EDGE_CANT_SET_TOP_LEFT "edge can't set top left"

# define MSG_ROOT_NOT_FOUND  "root not found"
# define MSG_PATH_NOT_FOUND  "path not found"

#endif //ERROR_H
