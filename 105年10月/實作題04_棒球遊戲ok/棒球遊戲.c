#include <stdio.h>
#include <string.h>
#define testdata "data2.txt"
#define NUM  9

int main()
{
    FILE *fp; //宣告檔案指標 
    fp=fopen(testdata,"r"); //開啟唯讀檔案 
    //記錄打擊資訊
    int strike[100]; //記錄打擊結果 
    int base[3]={0};//用來記錄各壘包是否有人的狀態 
    int i;
    int a; //代表球員總共打了幾次 
    
    for(i=0;i<NUM;++i) //讀取所有球員的打擊資訊 
    {
        fscanf(fp," %d",&a); //每一行開始有一個正整數a，代表球員總共打了a次 
        for(int j=0;j<a;++j)
        {
            /*
            接下來有 a 個字串（均為兩個字元），
            依序代表每次打擊的結果。
            資料之間均以一個空白字元隔開。
            */ 
            char str[2];//記錄每次打擊的結果 
            fscanf(fp,"%s",str);
            if(strcmp("FO",str)==0 |strcmp("GO",str)==0|strcmp("SO",str)==0)
                //如果打擊結果的字串"FO","GO","SO"三者之一,表示出局,則記錄為0 
                strike[j*9+i]=0;
            else if (strcmp("1B",str)==0) //如果1壘安打,則記錄為1 
                strike[j*9+i]=1;
            else if (strcmp("2B",str)==0) //如果2壘安打,則記錄為2 
                strike[j*9+i]=2;
            else if (strcmp("3B",str)==0) //如果3壘安打,則記錄為3 
                strike[j*9+i]=3;
            else //如果都不是上述情況,表示為HR,即全壘打,則記錄為4
                strike[j*9+i]=4;
        }
    }
   
    int out=0; //用來記錄目前此局的出局數
    int points=0; //目前得分 
    int index=0; //讀取到第幾筆資料 
    int b=0; //總出局數
    int count=0; //目前整場比賽已達多少個出局數  
    
	fscanf(fp,"%d",&b); //從檔案讀取總出局數
	while(count<b) //當目前出局數小於整場比賽的總出局數時 
    {
        switch(strike[index]) 
        {
            case 4: //全壘打
                for(int k=0;k<3;++k)
                {
                    //如果壘上有人得分，並清空壘包
                    if(base[k]==1)
                    {
                        points+=1;
                        base[k]=0;
                    }
                }
                points+=1;  //打擊者加一分
                break;
            case 1: //如果是一壘打 
                //如果三壘有人加一分，各壘往前推進 
                if(base[2]==1) points+=1;
                base[2]=base[1]; //二壘推進到三壘 
                base[1]=base[0]; //一壘推進到二壘 
                base[0]=1; //打擊者上 1 壘
                break;
            case 2: //如果是二壘打
                //如果三壘及二壘有人，各加一分
                if(base[2]==1) points+=1;
                if(base[1]==1) points+=1;
                base[2]=base[0]; //一壘推進到三壘
                base[0]=0; //一壘清空 
                base[1]=1; //打擊者上二壘
                break;
            case 3: //如果是三壘打
                //如果壘上有人各加 1 分
                if(base[2]==1) points+=1;
                if(base[1]==1) points+=1;
                if(base[0]==1) points+=1;
                base[1]=0; // 二壘清空
                base[0]=0; //一壘清空  
                base[2]=1; //打擊者上三壘
                break;
            default:  //如果是出局
                out+=1; //將目前此局的出局數累加 1 
                if(out==3) //如果三出局，清空壘包
                {
                    out=0; //將目前此局的出局數歸零, 換下一局的打擊 
                    base[0]=0; //一壘清空
                    base[1]=0; //二壘清空
                    base[2]=0; //三壘清空
                }
                count+=1;  //整場比賽的總出局數累加 1 
                break; 	
        } //switch指令結束 
        index+=1; //讀取筆數累加 1 ,接下來準備讀取下一筆資料 
    }
    printf("%d",points);
    return 0;
}
