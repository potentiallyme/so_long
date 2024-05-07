/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:28:13 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/05 20:09:50 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	welcome_message(void)
{
	ft_printf("\n                ");
	ft_printf("%s         HEY!", YLW);
	ft_printf("\n                ");
	ft_printf("      WELCOME TO\n\n%s%s", PPL, B);
	ft_printf("                ");
	ft_printf("L A B Y R I N T H O S\n\n%s", RST);
	ft_printf("                ");
	ft_printf("%s  A MAZE SOLVER GAME\n\n%s", YLW, RST);
	ft_printf("      ");
	ft_printf("%s%st a p  'I'  f o r  i n s t r u c t i o n s%s\n\n", FDE, BLU,
		RST);
	ft_printf("               ");
	ft_printf("%s************%s***********\n\n%s", BLU, R, RST);
}

void	instructions_message(void)
{
	ft_printf("%s\r\nLABYRINTHOS is a maze solving game, ", YLW);
	ft_printf("u must reach the end of the mazes without:\n");
	ft_printf("    %sGetting urself stuck%s", PPL, FDE);
	ft_printf(" %s- u can restart%s\n", R, RST);
	ft_printf("    %sTouching enemies%s", PPL, FDE);
	ft_printf(" %s- game will end%s\n", R, RST);
	ft_printf("    %sMissing any collectibles%s", PPL, FDE);
	ft_printf(" %s- u can't end%s\n\n", R, RST);
	ft_printf("%sUsing the following inputs:\n%s", YLW, PPL);
	ft_printf("%s    WASD or Arrow Keys to move\n    ", PPL);
	ft_printf("'R' to restart and try again\n");
	ft_printf("    ESC to quit the game\n\n");
	ft_printf("Ur character, %sV E N K A%s,", R, BLU);
	ft_printf(" will move until they reach a wall\n");
	ft_printf("Be careful, the path behind them closes");
	ft_printf(" as they move! Don't play urself...\n\n");
	ft_printf("%sIf u ever need this information again,", YLW);
	ft_printf(" tap 'I' and check ur terminal\n\n");
	ft_printf("                  * G L  &&  H F *%s\n\n", RST);
}
