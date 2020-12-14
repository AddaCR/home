using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace Sky.Common
{
    public class PopupHelper
    {
        public static async void ShowAlertDialog(string title, string message, Page page)
        {
            await page.DisplayAlert(title, message, "OK");
        }
    }
}
