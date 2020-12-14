using System;
using System.Collections.Generic;
using System.Text;

namespace Sky.Tab2_Discover
{
    public class HotelBookingData
    {
        public string ImagePath { get; set; }
        public string Title { get; set; }
        public string ImageNumberOfStars { get; set; }
        public double Price;
        public string PriceAsString { get { return "$" + Price; } }
    }
}
