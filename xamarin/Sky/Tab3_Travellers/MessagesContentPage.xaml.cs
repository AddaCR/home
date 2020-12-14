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
    public partial class MessagesContentPage : ContentPage
    {
        public ProfileDataViewModel VM => ((ProfileDataViewModel)BindingContext);
        public MessagesContentPage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();

            MessageData message_to_send = new MessageData()
            {
                ProfileImage = "tab1_travel_profilepicture_ryan.png",
                Received = false,
                Messages = new List<string>()
                 {
                     "Hi there!",
                     "I haven't seen you in a while",
                     "How are you ?!",
                     "Last time i saw you, you were 10 years old. Do you remember John's birthday party? We've gathered the entire family there, we were like 20 people in one room."

                 }
            };
            MessagesView.Children.Add(ConstructMessage(message_to_send));

            MessageData message_to_receive = new MessageData()
            {
                ProfileImage = "tab2_discover_profilepicture_small.png",
                Received = true,
                Messages = new List<string>()
                 {
                     "oh hi",
                     "I'm fantastic !",
                     "Let's meet up"
                 }
            };
            MessagesView.Children.Add(ConstructMessage(message_to_receive));

            MessageData message_reply = new MessageData()
            {
                ProfileImage = "tab1_travel_profilepicture_ryan.png",
                Received = false,
                Messages = new List<string>()
                 {
                     "Sure!!",
                 }
            };

            MessagesView.Children.Add(ConstructMessage(message_reply));
        }

        private void TapGestureRecognizer_Tapped(object sender, EventArgs e)
        {

        }

        private View ConstructMessage(MessageData message_to_send)
        {
            StackLayout wrapper = new StackLayout() { Orientation = StackOrientation.Vertical };
            Grid newGrid = new Grid()
            {
                ColumnDefinitions = new ColumnDefinitionCollection()
                {
                    new ColumnDefinition() {  Width = GridLength.Auto},
                    new ColumnDefinition() {  Width = GridLength.Star},
                    new ColumnDefinition() {  Width = GridLength.Auto}
                }
            };

            int row = 0;

            var background_color = message_to_send.Received ? Color.FromHex("#4527A0") : Color.FromHex("#707070");

            //StackLayout stackLayoutInner = new StackLayout() { Orientation = StackOrientation.Vertical };
            Image profileImage = new Image() { 
                Source = message_to_send.ProfileImage,
                HorizontalOptions = message_to_send.Received ? LayoutOptions.StartAndExpand : LayoutOptions.EndAndExpand
            };

            int number_of_messages = message_to_send.Messages.Count;
            for (int i = 0; i < number_of_messages - 1; i++)
            {
                Frame frame_with_message = CreateFrameFromText(message_to_send.Messages[i], background_color, message_to_send.Received);
                newGrid.Children.Add(frame_with_message, 1, row++);
            }

            string lastMessage = message_to_send.Messages[number_of_messages - 1];
            Frame frame_lastMessage = CreateFrameFromText(lastMessage, background_color, message_to_send.Received);
            newGrid.Children.Add(profileImage, message_to_send.Received ? 0 : 2, row);
            newGrid.Children.Add(frame_lastMessage, 1, row);

            wrapper.Children.Add(newGrid);
            return wrapper;
        }
        private Frame CreateFrameFromText(string message, Color background_color, bool received)
        {
            Label label_with_message = new Label()
            {
                Text = message,
                TextColor = Color.White
            };
            Frame frame_with_message = new Frame()
            {
                HasShadow = false,
                CornerRadius = 30,
                Margin = new Thickness(0, 10),
                Padding = new Thickness(10),
                Content = label_with_message,
                BackgroundColor = background_color,
                //HorizontalOptions = received ? LayoutOptions.StartAndExpand : LayoutOptions.EndAndExpand
            };
            return frame_with_message;
        }
    }
}