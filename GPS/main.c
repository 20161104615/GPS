//
//  main.c
//  GPS
//
//  Created by 20161104615 on 17/6/26.
//  Copyright © 2017年 20161104615. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
int main(){
    int i,n,k;
    char DLOfGPRMCNumber[24],DLOfGPGGANumber[24],time[6];
    FILE *f,*p,*t;
    f = fopen ("//Users//a20161104615//Desktop//GPS//GPS.txt","r+");
    p = fopen ("//Users//a20161104615//Desktop//GPS//GPS.txt","r+");
    t = fopen ("//Users//a20161104615//Desktop//GPS//GPS.csv","w");
    printf("请输入输出行数：");
    scanf("%d",&k);
    if (f==NULL&&p==NULL){
        printf("文件打开失败!\n");
    }
    else {
        fprintf(t,"时间,经度,经度,纬度,维度\n");
            for(n=0;n<k;n++){
                fseek(f, 7+n*122L, SEEK_CUR);
                printf("GPRMC时间为：");
                for (i=0;i<6;i++){
                    fscanf(f,"%c",&time[i]);
                    printf("%c",time[i]);
                }
                fseek(f, 0L, SEEK_SET);
                printf("\n");
                fseek(f, 7+n*122L, SEEK_CUR);
                fprintf(t,"%s,",time);
                fseek(f, 0L, SEEK_SET);
                
                
                fseek(f, 16+n*122L, SEEK_CUR);
                printf("GPRMC的经纬度为：");
                for (i=0;i<22;i++){
                    fscanf(f,"%c",&DLOfGPRMCNumber[i]);
                    printf("%c",DLOfGPRMCNumber[i]);
                }
                fseek(f,0L,SEEK_SET);
                printf("\n");
                fseek(f, 16+n*122L, SEEK_CUR);
                fprintf(t,"%s,\n",DLOfGPRMCNumber);
                fseek(f,0L,SEEK_SET);
                
                
                fseek(p, 70+n*122L, SEEK_CUR);
                printf("GPGGA时间为：");
                for (i=0;i<6;i++){
                    fscanf(p,"%c",&time[i]);
                    printf("%c",time[i]);
                }
                fseek(p, 0L, SEEK_SET);
                printf("\n");
                fseek(p, 70+n*122L, SEEK_CUR);
                fprintf(t,"%s,",time);
                fseek(p, 0L, SEEK_SET);
                
                
                fseek(p, 77+n*122L, SEEK_CUR);
                printf("GPGGA的经纬度为：");
                for (i=0;i<22;i++){
                    fscanf(p,"%c",&DLOfGPGGANumber[i]);
                    printf("%c",DLOfGPGGANumber[i]);
                }
                fseek(p,0L,SEEK_SET);
                printf("\n");
                fseek(p, 78+n*122L, SEEK_CUR);
                fprintf(t,"%s,\n",DLOfGPGGANumber);
                fseek(p,0L,SEEK_SET);
        } 
        fclose(f);
        fclose(p);
    }
    return 0;
}

