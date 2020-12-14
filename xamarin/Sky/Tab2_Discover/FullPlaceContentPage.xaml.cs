using Sky.Common;
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
    public partial class FullPlaceContentPage : ContentPage
    {
        private bool IsBooked = false;
        SwitchButtonViewModel viewModel = new SwitchButtonViewModel("tab2_discover_places_button_favorites_remove.png", "tab2_discover_places_button_favorites_add.png", false);
        public FullPlaceContentPage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
            SwitchButtonFavorite.BindingContext = viewModel;
            SwitchButtonFavorite.OnSwitchPressed += SwitchPressedFavourite;
        }

        private void ButtonPressed_BookPlace(object sender, EventArgs e)
        {
            ToggleState();
        }
        private void ToggleState()
        {
            IsBooked = !IsBooked;
            viewModel.Toggle();
            MainDatePickerInfo.Text = IsBooked ? "BOOKED" : "SELECT A DATE";
            BookingLabel.Text = IsBooked ? "CANCEL" : "BOOK THIS FOR $25.50";
            BookingLabelParent.BackgroundColor = IsBooked ? Color.Gray : Color.Default;
        }

        private void ButtonPressed_DatePicker(object sender, EventArgs e)
        {
            MainDatePicker.Focus();
        }

        private void SwitchPressedFavourite(object sender, EventArgs e)
        {
            // viewModel.Toggle();
        }

        private void MainDatePicker_DateSelected(object sender, DateChangedEventArgs e)
        {
            MainDatePickerInfo.Text = e.NewDate.Date.ToShortDateString();
        }
    }
}