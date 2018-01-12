
void timer(Text &minText, Text &secText, Text &miliText, Text &specText)
{
    minText.setFillColor(Color::Green);
    secText.setFillColor(Color::Green);
    miliText.setFillColor(Color::Green);
    minText.setPosition(900, 20);
    secText.setPosition(1000, 20);
    miliText.setPosition(1100, 20);
    specText.setFillColor(Color::Red);
    specText.setPosition(10, 10);
}
void timeDesign(int &min, int &sec, int &mili) // отнимает секунды/минуты/часы
{
    if (mili >= 0 || mili <= 59)
    {
        mili++;
    }
    if (mili == 59)
    {
        mili = 0;
        sec++;
    }
    if (mili == 59 || sec == 59)
    {
        mili = 0;
        sec = 0;
        min++;
    }
    if ((mili == 59) || (sec == 59) || (min == 23))
    {
        mili = 0;
        sec = 0;
        min = 0;
    }
    if (mili == 0 && sec == 0 && min == 0)
    {
        return;
    }
}
