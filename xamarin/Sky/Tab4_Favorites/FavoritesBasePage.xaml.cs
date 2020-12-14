using Sky.Common.CustomViews;
using Sky.Tab4_Favorites.CustomContentView;
using Sky.Tab4_Favorites.ViewModel;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Tab4_Favorites
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FavoritesBasePage : ContentPage
    {
        TabBarViewModel tabBarViewModel = new TabBarViewModel();
        SearchBarViewModel searchBarViewModel = new SearchBarViewModel("Search a favourite");
        private enum Page
        {
            Favourites = 0,
            Settings = 1
        };
        private Page currentPage = Page.Settings;

        public FavoritesBasePage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
            ButtonBottomLine.BindingContext = tabBarViewModel;
            SearchBar.BindingContext = searchBarViewModel;

            LoadContent(Page.Favourites);
        }

        private void LoadContent(Page newPage)
        {
            if (currentPage == newPage) return;
            UpdateButtonTextColor(currentPage, false);

            currentPage = newPage;
            tabBarViewModel.ColumnSelected = ((int)currentPage);
            SearchBarParent.IsVisible = (currentPage == Page.Favourites);
            UpdateButtonTextColor(currentPage, true);

            MyStackLayout.Children.Clear();
            MyStackLayout.Children.Add(Create(currentPage));
        }


        private View Create(Page newPage)
        {
            switch (newPage)
            {
                case Page.Favourites: return new TabFavourites_ContentView();
                case Page.Settings: return new TabSettings_ContentView();
            }
            
            return null;
        }


        private void UpdateButtonTextColor(Page newPage, bool enabled)
        {
            Color newColor = enabled ? Color.White : Color.Gray;
            switch (newPage)
            {
                case Page.Favourites: { ButtonFavourites.TextColor = newColor; break; }
                case Page.Settings: { ButtonSettings.TextColor = newColor; break; }
            }
        }

        private void ButtonPressed_Favourites(object sender, EventArgs e)
        {
            LoadContent(Page.Favourites);
        }

        private void ButtonPressed_Settings(object sender, EventArgs e)
        {
            LoadContent(Page.Settings);
        }
    }
}