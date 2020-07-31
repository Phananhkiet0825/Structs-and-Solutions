#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
typedef struct sach
{
 		int ms;
 		char name[41];
 		float 	price;
} Sach;
void NhapSach (Sach & a)
{
	printf("Ma so: ");
 	 scanf("%d",&a.ms);
 	 printf("Ten: ");
 	 fflush(stdin);
 	 gets(a.name);
 	 printf("Gia: ");
 	 scanf("%f",&a.price);
}
void InSach (Sach a)
{
	printf("Ma so: %d ",a.ms);
 
 	 printf("\tTen:%s ",a.name);
 	
 	 printf("\tGia: %.2f",a.price);
 	
}
void NhapMang (Sach a[], int n)
{
	for(int i=0;i<n;i++)
	{
	 printf("hay nhap thong tin cua sach %d \n",i);
	 NhapSach(a[i]);	
	}
}
void XuatMang (Sach a[], int n)
{
	for(int i=0;i<n;i++)
	{
	 printf("\n");
	 InSach(a[i]);	
	}
}
void Swap(Sach &a,Sach& b)
{
 	 Sach tam;
 	 tam = a;
 	 a=b;
 	 b= tam;
 	
}
void SortArray (Sach a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		if(a[i].ms>a[j].ms) Swap(a[i],a[j]);				  
	}
}
int TimKiemTuyenTinh (Sach a[], int n , int x)
{
	for (int i=0;i<n;i++)
		if (a[i].ms==x) return i;
	
	return -1;
}
int TimKiemNhiPhan(Sach a[], int n , int x)
{
 	int left=0;int right=n-1;
	while(left<=right)
	{
	int mid=(left+right)/2;
	if(a[mid].ms==x) return mid;
	if(x<a[mid].ms) right=mid-1;
	if(x>a[mid].ms) left=mid+1;			 	
 	}	
 	return -1;
}
int NameFinding(Sach a[], int n , char x[41])
{
	for (int i=0;i<n;i++)
		if(strcmp(a[i].name,x)==0)return i;
	
	return -1;
}
int HighestPrice(Sach a[], int n)
{
	 int x=0;
 	 for(int i=0;i<n-1;i++)
	{	
		if(a[i].price>a[i+1].price)x=a[i].price;				  
	}
}
void AllHighestPrice(Sach a[], int n)
{
	int x=HighestPrice( a, n);
	for(int i=0;i<n-1;i++)
	{	
		if(a[i].price==x) InSach(a[i]);				  
	}
}
int main ()
{
 	int n;
 	printf("moi ban nhap so luong phan tu cua mang ");
	scanf("%d",&n);
	Sach a[n];	
	NhapMang(a,n);
	printf("\nmang ban vua nhap la :");
	XuatMang(a,n);
	
	int x;
	int vt;
	printf("\n\n===========tim kiem tuyen tinh =============");
	printf("\nmoi ban nhap ma so sach can tim ");
	scanf("%d",&x);
	vt=TimKiemTuyenTinh(a,n,x);
	if(vt==-1)printf("\n=>khong tim thay so can tim ");
	else printf("=>ma so sach %d o vi tri %d",x,vt);
	
	printf("\n\n===========Tim kiem nhi phan ============");	
	SortArray(a,n);
	printf("\n****mang sau khi sap xep la ****");
	XuatMang(a,n);
	printf("\nmoi ban nhap sa so sach can tim ");
	scanf("%d",&x);
	vt=TimKiemNhiPhan(a,n,x);
	if(vt==-1)printf("\n=>khong tim thay ma so sach can tim ");
	else printf("=>ma so sach %d o vi tri %d",x,vt);
	
	printf("\n\n==============Tim kiem theo ten sach ============");
	char y[41];
	printf("\nhay nhap ten cuon sach can tim");
	gets(y);gets(y);
	vt=NameFinding(a,n,y);
	if(vt==-1)printf("\n=>khong tim thay ten cuon sach can tim ");
	else printf("=>sach %s o vi tri %d",y,vt); 
	 
	return 0;
}
