
#include <config.h>
#include <video_manager.h>
#include <string.h>

static PT_VideoOpr g_ptVideoOprHead = NULL;

/**********************************************************************
 * ????????? RegisterVideoOpr
 * ?????????? ???"???????", ??��????????????????��??????
 * ????????? ptVideoOpr - ???????,???"??????��?"?????????
 * ????????? ??
 * ?? ?? ??? 0 - ???, ????? - ???
 * ???????        ?��??     ?????	      ???????
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  ��???	      ????
 ***********************************************************************/
int RegisterVideoOpr(PT_VideoOpr ptVideoOpr)
{
	PT_VideoOpr ptTmp;

	if (!g_ptVideoOprHead)
	{
		g_ptVideoOprHead   = ptVideoOpr;
		ptVideoOpr->ptNext = NULL;
	}
	else
	{
		ptTmp = g_ptVideoOprHead;
		while (ptTmp->ptNext)
		{
			ptTmp = ptTmp->ptNext;
		}
		ptTmp->ptNext     = ptVideoOpr;
		ptVideoOpr->ptNext = NULL;
	}

	return 0;
}


/**********************************************************************
 * ????????? ShowVideoOpr
 * ?????????? ???????????????"???????"
 * ????????? ??
 * ????????? ??
 * ?? ?? ??? ??
 * ???????        ?��??     ?????	      ???????
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  ��???	      ????
 ***********************************************************************/
void ShowVideoOpr(void)
{
	int i = 0;
	PT_VideoOpr ptTmp = g_ptVideoOprHead;

	while (ptTmp)
	{
		printf("%02d %s\n", i++, ptTmp->name);
		ptTmp = ptTmp->ptNext;
	}
}

/**********************************************************************
 * ????????? GetVideoOpr
 * ?????????? ????????????????"???????"
 * ????????? pcName - ????
 * ????????? ??
 * ?? ?? ??? NULL   - ???,???????????, 
 *            ??NULL - ????????PT_VideoOpr???????
 * ???????        ?��??     ?????	      ???????
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  ��???	      ????
 ***********************************************************************/
PT_VideoOpr GetVideoOpr(char *pcName)
{
	PT_VideoOpr ptTmp = g_ptVideoOprHead;
	
	while (ptTmp)
	{
		if (strcmp(ptTmp->name, pcName) == 0)
		{
			return ptTmp;
		}
		ptTmp = ptTmp->ptNext;
	}
	return NULL;
}

int VideoDeviceInit(char *strDevName, PT_VideoDevice ptVideoDevice)
{
    int iError;
	PT_VideoOpr ptTmp = g_ptVideoOprHead;
	
	while (ptTmp)
	{
        iError = ptTmp->InitDevice(strDevName, ptVideoDevice);
        if (!iError)
        {
            return 0;
        }
		ptTmp = ptTmp->ptNext;
	}
    return -1;
}

/**********************************************************************
 * ????????? FontsInit
 * ?????????? ???????????????????????
 * ????????? ??
 * ????????? ??
 * ?? ?? ??? 0 - ???, ????? - ???
 * ???????        ?��??     ?????	      ???????
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  ��???	      ????
 ***********************************************************************/
int VideoInit(void)
{
	int iError;

    iError = V4l2Init();

	return iError;
}



