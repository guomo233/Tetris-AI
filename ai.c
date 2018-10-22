#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>

#define INF 0x7fffffff

#define DECLSPEC_EXPORT __declspec(dllexport)
#define WINAPI __stdcall

char gName[64]; // ���������ã�����ȫ��

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

// ����AI���֣�����ʾ�ڽ�����
DECLSPEC_EXPORT
char* WINAPI Name()
{
	strcpy(gName, "Lihanxi");
	return gName;
}

/* ======================================================== */

/* ��ȡ������� */
int get_hight (int boardW, int boardH, char board[])
{
	int i ;
	for (i=boardW*boardH; i>=0; i--)
		if (board[i] == '1')
			break ;

	return i >= 0 ? (i / boardW + 1) : 0 ;
}

/* ��ȡ�������� */
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

/* ��ȡbitmap�з����ˮƽ�߽� */
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

/* ��ȡbitmap�з������ֱ�߽� */
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

/* ��ȡbitmap�У�ˮƽx����͵� */
int get_bitmap_y (char bitmap[4][4], int x)
{
	int i, bitmap_y ;
	
	for (i=0; i<4; i++)
		if (bitmap[i][x])
			bitmap_y = i ;

	return bitmap_y ;
}

/* ����bitmap��ˮƽpos��bitmap��߽磩������״̬res�����������䷽�鶥��λ��y */
int after_down (char bitmap[4][4], int pos, int boardW, int boardH, char board[], char **res)
{
	int i, j, ii, bitmap_xl, bitmap_xr, bitmap_y, temp_bitmap_y, y = 0, min_dis = INF, dis ;
	int bitmap_yu, cur_top_y ;

	//��������λ��
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
	
	//�������º��ͼ
	*res = (char *) malloc (sizeof(char) * (strlen(board) + 1)) ;
	strcpy (*res, board) ;

	for (i=bitmap_y; i>=0; i--)
		for (j=0; j<4; j++)
		{
			int index = boardW * (y + bitmap_y - i) + (pos + j) ;
			if (index >= 0 && index < boardW * boardH && bitmap[i][j])
				(*res)[index] = '1' ;
		}

	//����
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

/* ���ظ���curPiece��bitmap����bitmap_i�Լ�����ת������rotate_count */
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

/* ��str���ҵ������ch�������س��ȣ�����߽�pos */
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

/* ���㷽��Ľ��նȣ�ÿ�е���������հ���֮�� */
int close_degree (int boardW, int boardH, char board[])
{
	int i, degree = 0, hight = get_hight (boardW, boardH, board) ;
	for (i=0; i<hight; i++)
		degree += max_continue (&board[boardW * i], boardW, '0', NULL) ;

	return degree ;
}

/* �����Ƿ���ڰ����а�����͹�������ذ��Ŀ��pit_width�Ͱ�����߽�pos */
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

/* �����Ϊ1�İ������� */
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

/* ��������curPiece��ѡ�����Ų��� */
void choice (char curPiece, int boardW, int boardH, char board[], int *bestX, int *bestRotation)
{
	int rotate_count, bitmap_i, x, r ;
	int max_score = -INF, pit_width ;
	
	get_cur (curPiece, &bitmap_i, &rotate_count) ;
	
	pit_width = get_pit (boardW, boardH, board, NULL) ;

	*bestX = 0, *bestRotation = 0 ;
	for (r=0; r<rotate_count; r++)
	{
		//����bitmap��board�еĺϷ����ұ߽�
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

			//û�а���͹���������ȶ��٣���θ߶�С����ν���
			if (pit_width < 1)
				score = -boardW * boardW * hole_count - boardW * hight + close ;
			//���ڰ���͹���������ȸ߶�С����ζ��٣���ν���
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
 * board��һ��boardW*boardH������01��ɵ��ַ�����ԭ�������½ǣ����к��С�
 * ����8*3�ĳ���ʵ����״��
 * 00000000
 * 00011001
 * 01111111
 * �����board������Ϊ��"011111110001100100000000"��
 *
 * Piece����ʹ���ַ� OISZLJT ���ո��ʾ������״��
 * nextPieceΪ' 'ʱ��ʾ��Ԥ����
 * curR�Ƿ�����1�ǳ�ʼ����2����ʱ��90�ȣ�3��180�ȣ�4��˳ʱ��90�ȡ�
 * curX,curY�����꣬���Ե�ǰ��4*4����������ڶ��У������ڶ���Ϊ��׼��
 *     ���½�Ϊx=1,y=1�����½�Ϊx=boardW,y=1�����Ͻ�Ϊx=1,y=boardH
 *     ���巽����״������һ��Ŀ¼�µ�pieces_orientations.jpg
 *     Ĭ�ϳ�ʼ����Ϊ curY==boardH-1, curX==boardW/2+1
 *
 * bestX,bestRotation ���ڷ�������λ�ã���curX,curR�Ĺ�����ͬ��
 *
 * ע�⣺�����������涨Ϊ����ת����ƽ�ƣ������¡�
 *       ���м����赲��AI����û���ж���ᵼ�´���ڷš�
 *       �ú����ڳ����·����ʱ�򱻵��ã�һ���������һ�Ρ�
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
	// ����ֱ���ڴ˺������¶ϵ�Ȼ�����е���

	choice (curPiece, boardW, boardH, board, bestX, bestRotation) ;
	*bestX += 3 ;
	*bestRotation += 1 ;

	return 0;
}

/*
 * path ���ڽ��ղ������̲����أ������ַ�����
 *      'l': ����һ��
 *      'r': ����һ��
 *      'd': ����һ��
 *      'L': ���Ƶ�ͷ
 *      'R': ���Ƶ�ͷ
 *      'D': ���Ƶ��ף�����ճ�ϣ��ɼ����ƶ���
 *      'z': ��ʱ����ת
 *      'c': ˳ʱ����ת
 * �ַ���ĩβҪ��'\0'����ʾ��ز�������Ӳ���䣩
 *
 * ������֧������·��������������Ҫ�˺���ֻ��ʹ������һ���Ļ�����ɾ������������
 * �����ڱ���������ǰһ���������ᱻ����
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
	// ���´˶δ���Ϊ����ԭ�ӿ�ʹ�ã�������Ҫ����ɾ��
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
