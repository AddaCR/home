using Sky.Common.CustomViews;
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
    public partial class DiscoverBasePage : ContentPage
    {
        SearchBarViewModel searchBarViewModel = new SearchBarViewModel("Type a place");

        public DiscoverBasePage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
            CustomSearchBar.BindingContext = searchBarViewModel;
        }
        protected override void OnAppearing()
        {
            base.OnAppearing();
        }

        private void Inner_Article_Big_Tapped(object sender, EventArgs e)
        {
            Navigation.PushAsync(new FullArticleContentPage());
        }

        private void Inner_PlaceCardsTapped(object sender, EventArgs e)
        {
            Navigation.PushAsync(new FullPlaceContentPage());
        }
    }
}