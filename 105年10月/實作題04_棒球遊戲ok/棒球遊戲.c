#include <stdio.h>
#include <string.h>
#define testdata "data2.txt"
#define NUM  9

int main()
{
    FILE *fp; //�ŧi�ɮ׫��� 
    fp=fopen(testdata,"r"); //�}�Ұ�Ū�ɮ� 
    //�O��������T
    int strike[100]; //�O���������G 
    int base[3]={0};//�ΨӰO���U�S�]�O�_���H�����A 
    int i;
    int a; //�N��y���`�@���F�X�� 
    
    for(i=0;i<NUM;++i) //Ū���Ҧ��y����������T 
    {
        fscanf(fp," %d",&a); //�C�@��}�l���@�ӥ����a�A�N��y���`�@���Fa�� 
        for(int j=0;j<a;++j)
        {
            /*
            ���U�Ӧ� a �Ӧr��]������Ӧr���^�A
            �̧ǥN��C�����������G�C
            ��Ƥ������H�@�Ӫťզr���j�}�C
            */ 
            char str[2];//�O���C�����������G 
            fscanf(fp,"%s",str);
            if(strcmp("FO",str)==0 |strcmp("GO",str)==0|strcmp("SO",str)==0)
                //�p�G�������G���r��"FO","GO","SO"�T�̤��@,��ܥX��,�h�O����0 
                strike[j*9+i]=0;
            else if (strcmp("1B",str)==0) //�p�G1�S�w��,�h�O����1 
                strike[j*9+i]=1;
            else if (strcmp("2B",str)==0) //�p�G2�S�w��,�h�O����2 
                strike[j*9+i]=2;
            else if (strcmp("3B",str)==0) //�p�G3�S�w��,�h�O����3 
                strike[j*9+i]=3;
            else //�p�G�����O�W�z���p,��ܬ�HR,�Y���S��,�h�O����4
                strike[j*9+i]=4;
        }
    }
   
    int out=0; //�ΨӰO���ثe�������X����
    int points=0; //�ثe�o�� 
    int index=0; //Ū����ĴX����� 
    int b=0; //�`�X����
    int count=0; //�ثe������ɤw�F�h�֭ӥX����  
    
	fscanf(fp,"%d",&b); //�q�ɮ�Ū���`�X����
	while(count<b) //��ثe�X���Ƥp�������ɪ��`�X���Ʈ� 
    {
        switch(strike[index]) 
        {
            case 4: //���S��
                for(int k=0;k<3;++k)
                {
                    //�p�G�S�W���H�o���A�òM���S�]
                    if(base[k]==1)
                    {
                        points+=1;
                        base[k]=0;
                    }
                }
                points+=1;  //�����̥[�@��
                break;
            case 1: //�p�G�O�@�S�� 
                //�p�G�T�S���H�[�@���A�U�S���e���i 
                if(base[2]==1) points+=1;
                base[2]=base[1]; //�G�S���i��T�S 
                base[1]=base[0]; //�@�S���i��G�S 
                base[0]=1; //�����̤W 1 �S
                break;
            case 2: //�p�G�O�G�S��
                //�p�G�T�S�ΤG�S���H�A�U�[�@��
                if(base[2]==1) points+=1;
                if(base[1]==1) points+=1;
                base[2]=base[0]; //�@�S���i��T�S
                base[0]=0; //�@�S�M�� 
                base[1]=1; //�����̤W�G�S
                break;
            case 3: //�p�G�O�T�S��
                //�p�G�S�W���H�U�[ 1 ��
                if(base[2]==1) points+=1;
                if(base[1]==1) points+=1;
                if(base[0]==1) points+=1;
                base[1]=0; // �G�S�M��
                base[0]=0; //�@�S�M��  
                base[2]=1; //�����̤W�T�S
                break;
            default:  //�p�G�O�X��
                out+=1; //�N�ثe�������X���Ʋ֥[ 1 
                if(out==3) //�p�G�T�X���A�M���S�]
                {
                    out=0; //�N�ثe�������X�����k�s, ���U�@�������� 
                    base[0]=0; //�@�S�M��
                    base[1]=0; //�G�S�M��
                    base[2]=0; //�T�S�M��
                }
                count+=1;  //������ɪ��`�X���Ʋ֥[ 1 
                break; 	
        } //switch���O���� 
        index+=1; //Ū�����Ʋ֥[ 1 ,���U�ӷǳ�Ū���U�@����� 
    }
    printf("%d",points);
    return 0;
}
