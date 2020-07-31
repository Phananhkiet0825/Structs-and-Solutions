#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void NhapMang (int a[], int n)
{
	for(int i=0;i<n;i++)
	{
	 scanf("%d",&(a[i]));	
	}
}
void XuatMang (int a[], int n)
{
	for(int i=0;i<n;i++)
	{
	 printf("%5d",a[i]);	
	}
}
void Swap(int &a,int& b)
{
 	 int tam;
 	 tam = a;
 	 a=b;
 	 b= tam;
 	
}
void SortArray (int a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		if(a[i]>a[j]) Swap(a[i],a[j]);				  
	}
}
int TimKiemTuyenTinh (int a[], int n , int x)
{
	for (int i=0;i<n;i++)
		if (a[i]==x) return i;
	
	return -1;
}
int TimKiemNhiPhan(int a[], int n , int x)
{
 	int left=0;int right=n-1;
	while(left<right)
	{
	int mid=(left+right)/2;
	if(a[mid]==x) return mid;
	if(x<a[mid]) right=mid-1;
	if(x>a[mid]) left=mid+1;			 	
 	}	
 	return -1;
}

int main ()
{
 	int n;
 	printf("moi ban nhap so luong phan tu cua mang ");
	scanf("%d",&n);
	int a[n];	
	NhapMang(a,n);
	printf("\nmang ban vua nhap la :");
	XuatMang(a,n);
	int x;
	int vt;
	printf("\ntim kiem tuyen tinh ");
	printf("\nmoi ban nhap so can tim ");
	scanf("%d",&x);
	vt=TimKiemTuyenTinh(a,n,x);
	if(vt==-1)printf("\nkhong tim thay so can tim ");
	else printf("so %d o vi tri %d",x,vt);
	printf("\ntim kiem nhi phan ");
	
	SortArray(a,n);
	printf("\nmang sau khi sap xep la ");
	XuatMang(a,n);
	printf("\nmoi ban nhap so can tim ");
	scanf("%d",&x);
	vt=TimKiemNhiPhan(a,n,x);
	if(vt==-1)printf("\nkhong tim thay so can tim ");
	else printf("so %d o vi tri %d",x,vt);
	return 0;
}
