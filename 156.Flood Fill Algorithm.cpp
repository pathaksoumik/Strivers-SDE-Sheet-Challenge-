void floodFillHelper(vector<vector<int>> &image, int i, int j, int oldColor, int newColor)
{
   
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size())
        return;
    

    if (image[i][j] != oldColor)
        return;
    
    if (image[i][j] == newColor)
        return;
    

    // Replace the colour of current pixel.
    image[i][j] = newColor;

    // Recur for adjacent pixels.
    floodFillHelper(image, i, j + 1, oldColor, newColor);
    floodFillHelper(image, i, j - 1, oldColor, newColor);
    floodFillHelper(image, i + 1, j, oldColor, newColor);
    floodFillHelper(image, i - 1, j, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];

    floodFillHelper(image, x, y, oldColor, newColor);

    return image;
}
