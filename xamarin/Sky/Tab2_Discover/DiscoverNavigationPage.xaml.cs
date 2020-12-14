using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Tab2_Discover
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class DiscoverNavigationPage : NavigationPage
    {
        public DiscoverNavigationPage()
        {
            InitializeComponent();
            SetHasNavigationBar(this, false);
            Navigation.PushAsync(new DiscoverBasePage());
        }
    }
}