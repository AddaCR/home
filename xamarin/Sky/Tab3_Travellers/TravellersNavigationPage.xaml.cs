using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Tab3_Travellers
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class TravellersNavigationPage : NavigationPage
    {
        public TravellersNavigationPage()
        {
            InitializeComponent();
            SetHasNavigationBar(this, false);
            Navigation.PushAsync(new TravellersBasePage());
        }
    }
}