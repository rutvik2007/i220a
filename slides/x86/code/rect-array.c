typedef struct {
  int x;	/** x-coordinate of lower-left corner */
  int y;	/** y-coordinate of lower-left corner */
  int color;	/** coding for color used to draw rectangle */
  int width;	/** width of rectange */
  int height;	/** height of rectangle */
} Rectangle;

int sum_perimeters(Rectangle rects[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += 2*(rects[i].width + rects[i].height);
  }
  return sum;
}
