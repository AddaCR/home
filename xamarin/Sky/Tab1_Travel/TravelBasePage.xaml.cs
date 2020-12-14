using Sky.Common;
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
    public partial class TravelBasePage : ContentPage
    {
        private Hotel myHotel;
        public TravelBasePage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
            myHotel = new Hotel() { Name = "The Whateeever Hotel", Location = "63 W 38Th St, New York , NY 10018" };
            //Whatever1.BindingContext = myHotel;
            //Whatever2.BindingContext = myHotel;
        }
        public TravelBasePage(string title)
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
            Title = title;
        }

        private void ButtonPressed_ViewBoardingPass(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("TravelBasePage", "Button pressed - View boarding pass", this);
        }

        private void ButtonPressed_Travel_NumberOfNights(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("TravelBasePage", "Button pressed - 4 nights", this);
        }

        private void ButtonPressed_AddPlans(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("TravelBasePage", "Button pressed - Add plans", this);
        }

        private void ButtonPressed_ChangeSource(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("TravelBasePage", "Button pressed - Change source", this);
        }

        private void ButtonPressed_ChangeDestination(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("TravelBasePage", "Button pressed - Change destination", this);
        }

        private void ButtonPressed_AddTravel(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("TravelBasePage", "Button pressed - Pick travel", this);
        }
    }
}