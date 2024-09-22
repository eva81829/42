/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:14:35 by fwu               #+#    #+#             */
/*   Updated: 2024/01/28 17:43:24 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char *get_number_0_to_19(int index)
{
	char *letters = 0;
	char **arr = 0;
	arr = malloc(sizeof(char *) * 20);
	arr[0] = "zero";
	arr[1] = "one";
	arr[2] = "two";
	arr[3] = "three";
	arr[4] = "four";
	arr[5] = "five";
	arr[6] = "six";
	arr[7] = "seven";
	arr[8] = "eight";	
	arr[9] = "nine";
	arr[10] = "ten";
	arr[11] = "eleven";
	arr[12] = "twelve";
	arr[13] = "thirteen";
	arr[14] = "fourteen";
	arr[15] = "fifteen";
	arr[16] = "sixteen";
	arr[17] = "seventeen";
	arr[18] = "eighteen";
	arr[19] = "nineteen";
	
	letters = arr[index];
	free(arr);
	return letters;
}

char *get_number_10_to_100(int index)
{
	char *letters = 0; 	
	char **arr = 0;
	arr = malloc(sizeof(char *) * 11);
	arr[0] = "";
	arr[1] = "ten";
	arr[2] = "twenty";
	arr[3] = "thirty";
	arr[4] = "forty";
	arr[5] = "fifty";
	arr[6] = "sixty";
	arr[7] = "seventy";
	arr[8] = "eighty";	
	arr[9] = "ninety";
	arr[10] = "hundred";

	letters = arr[index];
	free(arr);
	return letters;
}

char *get_number_more_than_1000(int index)
{
	char *letters = 0;	
	char **arr = 0;
	arr = malloc(sizeof(char *) * 12);
	arr[0] = "thousand";
	arr[1] = "million";
	arr[2] = "billion";
	arr[3] = "trillion";
	arr[4] = "quadrillion";
	arr[5] = "quintillion";
	arr[6] = "sextillion";
	arr[7] = "septillion";
	arr[8] = "octillion";
	arr[9] = "nonillion";
	arr[10] = "decillion";	
	arr[11] = "undecillion";

	letters = arr[index];
	free(arr);	
	return letters;
}