#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>

#define INF 0x7fffffff

#define DECLSPEC_EXPORT __declspec(dllexport)
#define WINAPI __stdcall

char gName[64]; // 返回名字用，必须全局

char gPieceBitmap[8][4][4][4] =
{
	// NULL
	{
		{
			{0},
		},
	},
	// O
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// I
	{
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
		},
	},
	// S
	{
		{
			{0, 0, 0, 0},
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
		},
	},
	// Z
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1},
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1},
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// L
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1},
			{0, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// J
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
		},
	},
	// T
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
		},
	},
};

#ifdef __cplusplus
extern "C" {
#endif

// 返回AI名字，会显示在界面上
DECLSPEC_EXPORT
char* WINAPI Name()
{
	strcpy(gName, "Lihanxi");
	return gName;
}

/* ======================================================== */

/* 获取整体最高 */
int get_hight (int boardW, int boardH, char board[])
{
	int i ;
	for (i=boardW*boardH; i>=0; i--)
		if (board[i] == '1')
			break ;

	return i >= 0 ? (i / boardW + 1) : 0 ;
}

/* 获取洞的数量 */
int count_holes (int boardW, int boardH, char board[])
{
	int i, j, flag, count = 0 ;

	for (j=0; j<boardW; j++)
	{
		flag = 0 ;
		for (i=boardH-1; i>=0; i--)
		{
			int index = i * boardW + j ;
			
			if (flag && board[index] == '0')
				count++ ;
			
			if (!flag && board[index] == '1')
				flag = 1 ;
		}
	}

	return count ;
}

/*int count_blanks (int boardW, int boardH, char board[], int ignore_top)
{
	int hight = get_hight (boardW, boardH, board) ;
	int i, j, count = 0 ;

	for (i=0; i<hight-ignore_top; i++)
		for (j=0; j<boardW; j++)
		{
			int index = boardW * i + j ;

			if (board[index] == '0')
				count++ ;
		}

	return count ;
}*/

/* 获取bitmap中方块的水平边界 */
void bitmap_range_x (char bitmap[4][4], int *bitmap_xl, int *bitmap_xr)
{
	int i, j ;
	*bitmap_xl = -1, *bitmap_xr = -1 ;

	for (j=0; j<4; j++)
		for (i=0; i<4; i++)
		{
			if (bitmap[i][j] && *bitmap_xl == -1)
				*bitmap_xl = j ;
			if (bitmap[i][j] && *bitmap_xl != -1)
				*bitmap_xr = j ;
		}
}

/* 获取bitmap中方块的竖直边界 */
void bitmap_range_y (char bitmap[4][4], int *bitmap_yu, int *bitmap_yd)
{
	int i, j ;
	*bitmap_yu = -1 ;

	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
		{
			if (bitmap[i][j] && *bitmap_yu == -1)
				*bitmap_yu = i ;
			if (bitmap_yd && bitmap[i][j] && *bitmap_yd != -1)
				*bitmap_yd = i ;
		}
}

/* 获取bitmap中，水平x的最低点 */
int get_bitmap_y (char bitmap[4][4], int x)
{
	int i, bitmap_y ;
	
	for (i=0; i<4; i++)
		if (bitmap[i][x])
			bitmap_y = i ;

	return bitmap_y ;
}

/* 计算bitmap以水平pos（bitmap左边界）下落后的状态res，并返回下落方块顶部位置y */
int after_down (char bitmap[4][4], int pos, int boardW, int boardH, char board[], char **res)
{
	int i, j, ii, bitmap_xl, bitmap_xr, bitmap_y, temp_bitmap_y, y = 0, min_dis = INF, dis ;
	int bitmap_yu, cur_top_y ;

	//计算下落位置
	bitmap_range_x (bitmap, &bitmap_xl, &bitmap_xr) ;
	for (j=bitmap_xl+pos; j<=bitmap_xr+pos; j++)
	{
		for (i=boardH-1; i>=0; i--)
		{
			int index = i * boardW + j ;
			
			if (board[index] == '1')
				break ;
		}

		temp_bitmap_y = get_bitmap_y (bitmap, j-pos) ;
		dis = boardH - i - 1 - temp_bitmap_y ;
		if (dis < min_dis)
		{
			min_dis = dis ;
			bitmap_y = temp_bitmap_y ;
			y = i + 1 ;
		}
		else if (dis == min_dis && temp_bitmap_y > bitmap_y)
		{
			bitmap_y = temp_bitmap_y ;
			y = i + 1 ;
		}
	}
	bitmap_range_y (bitmap, &bitmap_yu, NULL) ;
	cur_top_y = y + bitmap_y - bitmap_yu ;
	
	//绘制落下后的图
	*res = (char *) malloc (sizeof(char) * (strlen(board) + 1)) ;
	strcpy (*res, board) ;

	for (i=bitmap_y; i>=0; i--)
		for (j=0; j<4; j++)
		{
			int index = boardW * (y + bitmap_y - i) + (pos + j) ;
			if (index >= 0 && index < boardW * boardH && bitmap[i][j])
				(*res)[index] = '1' ;
		}

	//消行
	for (i=0, ii=0; i<boardH; i++, ii++)
	{
		int layer_count = 0 ;
		for (j=0; j<boardW; j++)
		{
			int index_up = boardW * i + j ;
			int index_down = boardW * ii + j ;

			(*res)[index_down] = (*res)[index_up] ;

			if ((*res)[index_up] == '1')
				layer_count++ ;
		}
		
		if (layer_count == boardW)
		{
			ii-- ;
			cur_top_y-- ;
		}
	}

	return cur_top_y ;
}

/* 返回给定curPiece的bitmap索引bitmap_i以及可旋转的数量rotate_count */
void get_cur (char curPiece, int *bitmap_i, int *rotate_count)
{
	if (curPiece == 'O')
	{
		*bitmap_i = 1 ;
		*rotate_count = 1 ;
	}
	else if (curPiece == 'I')
	{
		*bitmap_i = 2 ;
		*rotate_count = 2 ;
	}
	else if (curPiece == 'S')
	{
		*bitmap_i = 3 ;
		*rotate_count = 2 ;
	}
	else if (curPiece == 'Z')
	{
		*bitmap_i = 4 ;
		*rotate_count = 2 ;
	}
	else if (curPiece == 'L')
	{
		*bitmap_i = 5 ;
		*rotate_count = 4 ;
	}
	else if (curPiece == 'J')
	{
		*bitmap_i = 6 ;
		*rotate_count = 4 ;
	}
	else
	{
		*bitmap_i = 7 ;
		*rotate_count = 4 ;
	}
}

void swap (int *a, int *b)
{
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}

/* 从str中找到最长连续ch，并返回长度，和左边界pos */
int max_continue (char str[], int length, char ch, int *pos)
{
	int i, max_ctn = 0, ctn = 0 ;
	
	for (i=0; i<length; i++)
	{
		if (i == 0 && str[i] == ch)
			ctn = 1 ;
		if (i + 1 < length && str[i+1] == ch)
			ctn++ ;
		if ((i + 1 >= length || (i + 1 < length && str[i+1] != ch)) && str[i] == ch)
		{
			max_ctn = ctn > max_ctn ? ctn : max_ctn ;
			ctn = 0 ;
			if (pos)
				*pos = i ;
		}
	}
	
	if (pos)
		*pos = *pos - max_ctn + 1 ;
	return max_ctn ;
}

/* 计算方块的紧凑度，每行的最大连续空白数之和 */
int close_degree (int boardW, int boardH, char board[])
{
	int i, degree = 0, hight = get_hight (boardW, boardH, board) ;
	for (i=0; i<hight; i++)
		degree += max_continue (&board[boardW * i], boardW, '0', NULL) ;

	return degree ;
}

/* 计算是否存在凹（有凹必有凸），返回凹的宽度pit_width和凹的左边界pos */
int get_pit (int boardW, int boardH, char board[], int *pos)
{
	int i, j, hight = get_hight (boardW, boardH, board), pit_width ;
	char *pits = (char *) malloc (sizeof(char) * boardW) ;

	for (j=0; j<boardW; j++)
	{
		for (i=hight-1; i>=0; i--)
		{
			int index = boardW * i + j ;
			if (board[index] == '1')
				break ;
		}
		
		pits[j] = (i < (hight - 4) ? '1' : '0') ;
	}

	pit_width = max_continue (pits, boardW, '1', pos) ;

	free (pits) ;
	return pit_width ;
}

/* 计算宽为1的凹的数量 */
int count_pits (int boardW, int boardH, char board[])
{
	int i, j, hight = get_hight (boardW, boardH, board), count ;
	char *hights = (char *) malloc (sizeof(char) * boardW + 2) ;

	for (j=0; j<boardW; j++)
	{
		for (i=hight-1; i>=0; i--)
		{
			int index = boardW * i + j ;
			if (board[index] == '1')
			{
				hights[j+1] = i ;
				break ;
			}
		}
	}
	hights[0] = boardH ;
	hights[j] = boardH ;

	for (j=1; j<=boardW; j++)
		if (hights[j] < hights[j+1] && hights[j] < hights[j-1])
			count++ ;

	free (hights) ;
	return count ;
}

int iscover (int a, int b, int x, int y)
{
	if (a > x)
	{
		swap (&a, &x) ;
		swap (&b, &y) ;
	}

	return b > x ;
}

/* 给定方块curPiece，选择最优策略 */
void choice (char curPiece, int boardW, int boardH, char board[], int *bestX, int *bestRotation)
{
	int rotate_count, bitmap_i, x, r ;
	int max_score = -INF, pit_width ;
	
	get_cur (curPiece, &bitmap_i, &rotate_count) ;
	
	pit_width = get_pit (boardW, boardH, board, NULL) ;

	*bestX = 0, *bestRotation = 0 ;
	for (r=0; r<rotate_count; r++)
	{
		//计算bitmap在board中的合法左右边界
		int min_x, max_x, bitmap_xl, bitmap_xr ;
		bitmap_range_x (gPieceBitmap[bitmap_i][r], &bitmap_xl, &bitmap_xr) ;
		min_x = -bitmap_xl ;
		max_x = boardW - bitmap_xr - 1 ;

		for (x=min_x; x<=max_x; x++)
		{
			char *res ;
			int hole_count, hight, close ;
			int score ;

			after_down (gPieceBitmap[bitmap_i][r], x, boardW, boardH, board, &res) ;
			hole_count = count_holes (boardW, boardH, res) ;
			hight = get_hight (boardW, boardH, res) ;
			close = close_degree (boardW, boardH, res) ;

			//没有凹（凸），则优先洞少，其次高度小，其次紧凑
			if (pit_width < 1)
				score = -boardW * boardW * hole_count - boardW * hight + close ;
			//存在凹（凸），则优先高度小，其次洞少，其次紧凑
			else
				score = -boardW * hole_count - boardW * boardW * hight + close ;
			
			if (score > max_score)
			{
				max_score = score ;
				*bestX = x ;
				*bestRotation = r ;
			}

			free(res) ;
		}
	}
}

/* ======================================================== */

/*
 * board是一个boardW*boardH长度用01组成的字符串，原点于左下角，先行后列。
 * 例如8*3的场地实际形状：
 * 00000000
 * 00011001
 * 01111111
 * 则参数board的内容为："011111110001100100000000"。
 *
 * Piece参数使用字符 OISZLJT 及空格表示方块形状。
 * nextPiece为' '时表示无预览。
 * curR是方向朝向，1是初始方向，2是逆时针90度，3是180度，4是顺时针90度。
 * curX,curY的坐标，是以当前块4*4矩阵的上数第二行，右数第二列为基准，
 *     左下角为x=1,y=1；右下角为x=boardW,y=1；左上角为x=1,y=boardH
 *     具体方块形状参阅上一级目录下的pieces_orientations.jpg
 *     默认初始坐标为 curY==boardH-1, curX==boardW/2+1
 *
 * bestX,bestRotation 用于返回最优位置，与curX,curR的规则相同。
 *
 * 注意：方块操作次序规定为先旋转，再平移，最后放下。
 *       若中间有阻挡而AI程序没有判断则会导致错误摆放。
 *       该函数在出现新方块的时候被调用，一个方块调用一次。
 */
DECLSPEC_EXPORT
int WINAPI AI(int boardW, int boardH,
		char board[],
		char curPiece,
		int curX, int curY,
		int curR,
		char nextPiece,
		int* bestX, int* bestRotation)
{
	// 可以直接在此函数内下断点然后运行调试

	choice (curPiece, boardW, boardH, board, bestX, bestRotation) ;
	*bestX += 3 ;
	*bestRotation += 1 ;

	return 0;
}

/*
 * path 用于接收操作过程并返回，操作字符集：
 *      'l': 左移一格
 *      'r': 右移一格
 *      'd': 下移一格
 *      'L': 左移到头
 *      'R': 右移到头
 *      'D': 下移到底（但不粘上，可继续移动）
 *      'z': 逆时针旋转
 *      'c': 顺时针旋转
 * 字符串末尾要加'\0'，表示落地操作（或硬降落）
 *
 * 本函数支持任意路径操作，若不需要此函数只想使用上面一个的话，则删掉本函数即可
 * 若存在本函数，则前一个函数不会被调用
 */
DECLSPEC_EXPORT
int WINAPI AIPath(int boardW, int boardH,
		char board[],
		char curPiece,
		int curX, int curY,
		int curR,
		char nextPiece,
		char path[] )
{
	// 以下此段代码为兼容原接口使用，若不需要可以删除
	//if (0)
	{
		int bestX = 0;
		int bestRotation = 0;
		AI(boardW, boardH,
			board,
			curPiece,
			curX, curY,
			curR,
			nextPiece,
			&bestX, &bestRotation
			);
		while ( curR != bestRotation )
		{
			strcat(path, "z");
			curR = curR % 4 + 1;
		}
		while ( curX > bestX )
		{
			strcat(path, "l");
			curX -= 1;
		}
		while ( curX < bestX )
		{
			strcat(path, "r");
			curX += 1;
		}
	}
	//strcpy(path, "ddddddddddcccrrrrrrDL");
	return 0;
}

#ifdef __cplusplus
}
#endif
