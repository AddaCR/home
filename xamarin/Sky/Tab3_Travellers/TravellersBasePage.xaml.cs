using Sharpnado.Presentation.Forms.ViewModels;
using Sky.Tab3_Travellers.ViewModel;
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
    public partial class TravellersBasePage : ContentPage
    {
        public TravellersBasePage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
        }
        private async void AccountListView_ItemTapped(object sender, ItemTappedEventArgs e)
        {
            await Navigation.PushAsync(new ProfileTabContentPage());
        }
        private async void MessageButton_Clicked(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new MessagesContentPage());
        }
        protected override void OnAppearing()
        {
            base.OnAppearing();
            UpdateList();
        }
        private void UpdateList()
        {
            List<TravellersViewModel> users = new List<TravellersViewModel>()
            {
                new TravellersViewModel() { Name = "James Harrington", Description = "Director of Software and Engineering at WorkHard Inc.", ProfilePicturePath="tab3_travellers_profilepicture_1.png"},
                new TravellersViewModel() { Name = "Lacey-Mae Howe", Description = "I love to ride a bike every now and then. Enjoy coffee, whisky and red wine.", ProfilePicturePath="tab3_travellers_profilepicture_2.png"},
                new TravellersViewModel() { Name = "Amy Ford", Description = "I'm a happy person with mediocre dance moves. Originally from San Diego.", ProfilePicturePath="tab3_travellers_profilepicture_3.png"},
                new TravellersViewModel() { Name = "Susie Wright", Description = "Fashion blogger at WhatIf.", ProfilePicturePath="tab3_travellers_profilepicture_4.png"},
            };

            AccountListView.ItemsSource = users;
        }
    }
}