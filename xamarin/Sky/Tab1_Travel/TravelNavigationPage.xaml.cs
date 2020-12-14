using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Tab1_Travel
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class TravelNavigationPage : NavigationPage
    {
        public TravelNavigationPage()
        {
            InitializeComponent();
            Navigation.PushAsync(new TravelBasePage());
        }
    }
}