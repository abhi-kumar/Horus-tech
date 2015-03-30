#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}
 
// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}

// A utility function to swap to integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function to print an array
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// A function to generate a random permutation of arr[]
void randomize ( int arr[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

String face_cascade_name = "xml/1.xml";
String face_cascade_name2 = "xml/2.xml";
String face_cascade_name3 = "xml/3.xml";
String face_cascade_name4 = "xml/4.xml";
String face_cascade_name5 = "xml/5.xml";
String face_cascade_name6 = "xml/6.xml";
String face_cascade_name7 = "xml/7.xml";
String face_cascade_name8 = "xml/8.xml";
String face_cascade_name9 = "xml/9.xml";
String face_cascade_name10 = "xml/10.xml";

CascadeClassifier face_cascade;
CascadeClassifier face_cascade2;
CascadeClassifier face_cascade3;
CascadeClassifier face_cascade4;
CascadeClassifier face_cascade5;
CascadeClassifier face_cascade6;
CascadeClassifier face_cascade7;
CascadeClassifier face_cascade8;
CascadeClassifier face_cascade9;
CascadeClassifier face_cascade10;
string window_name = "Capture - Face detection";
RNG rng(12345);
Mat src;
Mat detectAndDisplay( Mat src );

int main( int argc, char* argv[] )
{
	Mat frames = imread(argv[1],1);
	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade2.load( face_cascade_name2 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade3.load( face_cascade_name3 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade4.load( face_cascade_name4 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade5.load( face_cascade_name5 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade6.load( face_cascade_name6 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade7.load( face_cascade_name7 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade8.load( face_cascade_name8 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade9.load( face_cascade_name9 ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !face_cascade10.load( face_cascade_name10 ) ){ printf("--(!)Error loading\n"); return -1; };
	int rows = frames.rows;
	int cols = frames.cols;
/*	Mat roi1 = frames(Rect (0,0,cols/3,rows));
	Mat l1 = roi1.clone();
	Mat roi2 = frames(Rect (cols/3,0,cols/3,rows));
	Mat l2 = roi2.clone();
	Mat roi3 = frames(Rect (2*cols/3,0,cols/3 ,rows));
	Mat l3 = roi3.clone();
	l1 = detectAndDisplay(l1);
	l2 = detectAndDisplay(l2);
	l3 = detectAndDisplay(l3);	
	imshow("l1",l1);
	imshow("l2",l2);
	imshow("l3",l3);
*/	frames = detectAndDisplay( frames );	
	imshow("frames",frames);
	waitKey(0);
	return 0;
}

Mat detectAndDisplay( Mat src)
{
	int pic_number = 0;
	Mat frame = src.clone();	
	std::vector<Rect> faces;
	int cols = frame.cols;
	int rows = frame.rows;
	Mat frame_gray;
	cvtColor( frame, frame_gray, CV_BGR2GRAY );
	equalizeHist( frame_gray, frame_gray );
	face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0) );
	int center_x[100];
	int center_y[100];
	char z[100] = ".jpg";
	for (int i = 0; i<100; i++)
	{
		center_x[i] = -1;
		center_y[i] = -1;
	}
	int number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "inital = " << number << endl;
	char a[100] = "faces/";
	char b[100] = "";
	char d[100] = "";
	for( size_t i = 0; i < faces.size(); i++ )
	{
		Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		center_x[i] = faces[i].x;
		center_y[i] = faces[i].y;
		Mat roi = src(Rect(faces[i].x-10,faces[i].y-10,faces[i].width+20,faces[i].height+20));
		char a[100] = "faces/";
		char b[100] = "";
		char d[100] = "";
		strcat(d,a);
		
		itoa(pic_number,b,10);
		strcat(d,b);
		strcat(d,z);
		cout << d << endl;
		imwrite(d,roi);
		pic_number++;
		ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 0, 0, 255 ), 4, 8, 0 );
		Mat faceROI = frame_gray( faces[i] );
	}
	
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 1st iter = " << number << endl;
	std::vector<Rect> faces2;
	face_cascade2.detectMultiScale( frame_gray, faces2, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces2.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces2[i].x > center_x[j] - 20 && faces2[i].x < center_x[j] + 20) && ( faces2[i].y > center_y[j] - 20 && faces2[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces2[i].x + faces2[i].width*0.5, faces2[i].y + faces2[i].height*0.5 );
			ellipse( frame, center, Size( faces2[i].width*0.5, faces2[i].height*0.5), 0, 0, 360, Scalar( 0, 255, 0 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces2[i] );
			Mat roi = src(Rect(faces2[i].x-10,faces2[i].y-10,faces2[i].width+20,faces2[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces2[i].x;
					center_y[k] = faces2[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 2nd iter = " << number << endl;
	std::vector<Rect> faces3;
	face_cascade3.detectMultiScale( frame_gray, faces3, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces3.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces3[i].x > center_x[j] - 20 && faces3[i].x < center_x[j] + 20) && ( faces3[i].y > center_y[j] - 20 && faces3[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces3[i].x + faces3[i].width*0.5, faces3[i].y + faces3[i].height*0.5 );
			ellipse( frame, center, Size( faces3[i].width*0.5, faces3[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 0 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces3[i] );
			Mat roi = src(Rect(faces3[i].x-10,faces3[i].y-10,faces3[i].width+20,faces3[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces3[i].x;
					center_y[k] = faces3[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 3rd iter = " << number << endl;
	std::vector<Rect> faces4;
	face_cascade4.detectMultiScale( frame_gray, faces4, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces4.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces4[i].x > center_x[j] - 20 && faces4[i].x < center_x[j] + 20) && ( faces4[i].y > center_y[j] - 20 && faces4[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces4[i].x + faces4[i].width*0.5, faces4[i].y + faces4[i].height*0.5 );
			ellipse( frame, center, Size( faces4[i].width*0.5, faces4[i].height*0.5), 0, 0, 360, Scalar( 255, 255, 0 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces4[i] );
			Mat roi = src(Rect(faces4[i].x-10,faces4[i].y-10,faces4[i].width+20,faces4[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces4[i].x;
					center_y[k] = faces4[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 4th iter = " << number << endl;
	std::vector<Rect> faces5;
	face_cascade5.detectMultiScale( frame_gray, faces5, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces5.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces5[i].x > center_x[j] - 20 && faces5[i].x < center_x[j] + 20) && ( faces5[i].y > center_y[j] - 20 && faces5[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces5[i].x + faces5[i].width*0.5, faces5[i].y + faces5[i].height*0.5 );
			ellipse( frame, center, Size( faces5[i].width*0.5, faces5[i].height*0.5), 0, 0, 360, Scalar( 0, 255, 255 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces5[i] );
			Mat roi = src(Rect(faces5[i].x-10,faces5[i].y-10,faces5[i].width+20,faces5[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces5[i].x;
					center_y[k] = faces5[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 5th iter = " << number << endl;
	std::vector<Rect> faces6;
	face_cascade6.detectMultiScale( frame_gray, faces6, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces6.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces6[i].x > center_x[j] - 20 && faces6[i].x < center_x[j] + 20) && ( faces6[i].y > center_y[j] - 20 && faces6[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces6[i].x + faces6[i].width*0.5, faces6[i].y + faces6[i].height*0.5 );
			ellipse( frame, center, Size( faces6[i].width*0.5, faces6[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces6[i] );
			Mat roi = src(Rect(faces6[i].x-10,faces6[i].y-10,faces6[i].width+20,faces6[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces6[i].x;
					center_y[k] = faces6[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 6th iter = " << number << endl;
	std::vector<Rect> faces7;
	face_cascade7.detectMultiScale( frame_gray, faces7, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0) );
	for( size_t i = 0; i < faces7.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces7[i].x > center_x[j] - 20 && faces7[i].x < center_x[j] + 20) && ( faces7[i].y > center_y[j] - 20 && faces7[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces7[i].x + faces7[i].width*0.5, faces7[i].y + faces7[i].height*0.5 );
			ellipse( frame, center, Size( faces7[i].width*0.5, faces7[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces7[i] );
			Mat roi = src(Rect(faces7[i].x-10,faces7[i].y-10,faces7[i].width+20,faces7[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces7[i].x;
					center_y[k] = faces7[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 7th iter = " << number << endl;
	std::vector<Rect> faces8;
	face_cascade8.detectMultiScale( frame_gray, faces6, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces8.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces8[i].x > center_x[j] - 20 && faces8[i].x < center_x[j] + 20) && ( faces8[i].y > center_y[j] - 20 && faces8[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces8[i].x + faces8[i].width*0.5, faces8[i].y + faces8[i].height*0.5 );
			ellipse( frame, center, Size( faces8[i].width*0.5, faces8[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces8[i] );
			Mat roi = src(Rect(faces8[i].x-10,faces8[i].y-10,faces8[i].width+20,faces8[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces8[i].x;
					center_y[k] = faces8[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 8th iter = " << number << endl;
	std::vector<Rect> faces9;
	face_cascade9.detectMultiScale( frame_gray, faces9, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0)  );
	for( size_t i = 0; i < faces9.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces9[i].x > center_x[j] - 20 && faces9[i].x < center_x[j] + 20) && ( faces9[i].y > center_y[j] - 20 && faces9[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces9[i].x + faces9[i].width*0.5, faces9[i].y + faces9[i].height*0.5 );
			ellipse( frame, center, Size( faces9[i].width*0.5, faces9[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces9[i] );
			Mat roi = src(Rect(faces9[i].x-10,faces9[i].y-10,faces9[i].width+20,faces9[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces9[i].x;
					center_y[k] = faces9[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 9th iter = " << number << endl;
	std::vector<Rect> faces10;
	face_cascade10.detectMultiScale( frame_gray, faces10, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0) );
	for( size_t i = 0; i < faces10.size(); i++ )
	{
		int flag = 1;		
		for( int j = 0; center_x[j] != -1;j++)
		{
			if(( faces10[i].x > center_x[j] - 20 && faces10[i].x < center_x[j] + 20) && ( faces10[i].y > center_y[j] - 20 && faces10[i].y < center_y[j] + 20))
			{				
				flag = 0;
				break;
			}				
		}
		if(flag == 1)
		{
			Point center( faces10[i].x + faces10[i].width*0.5, faces10[i].y + faces10[i].height*0.5 );
			ellipse( frame, center, Size( faces10[i].width*0.5, faces10[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );			
			Mat faceROI = frame_gray( faces10[i] );
			Mat roi = src(Rect(faces10[i].x-10,faces10[i].y-10,faces10[i].width+20,faces10[i].height+20));
			char a[100] = "faces/";
			char b[100] = "";
			char d[100] = "";
			strcat(d,a);
			
			itoa(pic_number,b,10);
			strcat(d,b);
			strcat(d,z);
			cout << d << endl;
			imwrite(d,roi);
			pic_number++;
			for(int k = 0; k < 100; k++)
			{
				if(center_x[k] == -1)
				{
					center_x[k] = faces10[i].x;
					center_y[k] = faces10[i].y;
					break;
				}
			} 
		}

			
	}
	number = 0;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			number++;
		}
	}
	cout << "faces detected after 10th iter = " << number << endl;
	for(int k = 0; k < 100; k++)
	{
		if(center_x[k] != -1)
		{
			cout << center_x[k] << " " << center_y[k] << endl;
		}
	}
//	imshow( window_name, frame );
	return frame;
}
