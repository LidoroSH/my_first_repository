# include <stdio.h>
typedef struct 
{
    float x;
    float y;
}
Point2D;

typedef struct 
{
    Point2D p1;
    Point2D p2;
    Point2D p3;
    Point2D p4;
}
Rectangle;

//creating a rectangle with some terminlogy that yeild some inner order relation logic between coordinated of rectangle
// we only need 4 parmeters (2 pairs of 2d point) to define uniquely rectangle beacause of it's symmetry group...
Rectangle CreateRectangle(Point2D p1, Point2D p3){
    if (p1.x >= p3.x || p1.y>=p3.y){
    printf("p1 should be bottom left and p2 should be up-rigth\n");
    }
    Rectangle my_rec;
    my_rec.p1 = p1;
    my_rec.p3 = p3;
    my_rec.p2.x= my_rec.p1.x;
    my_rec.p2.y = my_rec.p3.y;
    my_rec.p4.x = my_rec.p3.x;
    my_rec.p4.y = my_rec.p1.y;
    return my_rec;

}
// some function that determines EXSITENCE of intersetion between rec1 and rec2.
// need to take 2 rectangles and return 1 if intersection occures and return zero if intersection don't occur...
int IntersectionExistence  (Rectangle rec1,Rectangle rec2) {
    if (rec1.p1.x > rec2.p3.x){
    printf("rec1 is to rigth to rec2\n");
    return 0;
    } 
    else if (rec1.p3.x < rec2.p1.x )
    {
        printf("rec1 is to the left to rec2\n");
        return 0;
    }
    else if (rec1.p1.y > rec2.p3.y)
    {
        printf("rec1 is above rec2\n");
        return 0;
    }
    else if (rec1.p3.y < rec2.p1.y)
    {
        printf("rect 1 is below rec 2\n");
        return 0;
    }
    
    
    else { printf("there is intersection\n");
        return 1;}
}




//here we already know that our two rectangles are intersecting... so, 
// so we need FUNCTION THAT EATS TWO INTERSCTING TRIANGLE AND RETURN TRAINGLE(FOR THE PRIVATE CASE THAT THE TWO RECTANGLES ARE EQUIORINTED IN SPACE)
// the max between rec1.p1.x and rec2.p1.x = rec_int.p1.x, the min between rec1.p3.x and rec2.p3.x = rec_int.p3.x
// the max between rec1.p1.y and rec2.p1.y = rec_int.p1.y , the min between rec1.p3.y and rec2.p3.y = rec_int.p3.y 
 Rectangle IntersetedRectangle (Rectangle rec1, Rectangle rec2){
    Point2D p1,p3;
    p1.x = (rec1.p1.x > rec2.p1.x) ? rec1.p1.x : rec2.p1.x;
    p1.y = (rec1.p1.y > rec2.p1.y) ? rec1.p1.y : rec2.p1.y;
    p3.x = (rec1.p3.x < rec2.p3.x) ? rec1.p3.x : rec2.p3.y;
    p3.y = (rec1.p3.y < rec2.p3.y) ? rec1.p3.y : rec2.p3.y;
    return CreateRectangle(p1,p3);
 }




int main() {
Point2D p1 = {0,0};
Point2D p3 ={1,1};
Point2D p5 = {0,0};
Point2D p7 = {1,1};
Rectangle rec1 = CreateRectangle(p1,p3);
Rectangle rec2 = CreateRectangle(p5,p7);
printf("for rec1: left-bottom =(%f,%f), rigth up= (%f,%f)\n", rec1.p1.x,rec1.p1.y,rec1.p3.x,rec1.p3.y);
printf("for rec2: left-bottom = (%f,%f), up-rigth = (%f,%f)\n ", rec2.p1.x, rec2.p1.y, rec2.p3.x, rec2.p3.y);
int exsitence = IntersectionExistence(rec1,rec2);
if(exsitence == 1){
    Rectangle intersected_rectangle = IntersetedRectangle(rec1,rec2);
    printf("the left-bottom intersected rectangle is with coordinates (%f,%f)\n and the rigth-up interseted rectnagle is with coordinates (%f,%f)\n don't forget we assume standatd basis adn equ-orinted rectangles both in cartesian basis",intersected_rectangle.p1.x,intersected_rectangle.p1.y,intersected_rectangle.p3.x,intersected_rectangle.p3.y);
}


}
// some chanfe in the file
// some more changes for checkig git
//another git change