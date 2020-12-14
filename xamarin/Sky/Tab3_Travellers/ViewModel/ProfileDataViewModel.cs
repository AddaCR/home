using System;
using System.Collections.Generic;
using System.Text;

namespace Sky.Tab3_Travellers.ViewModel
{
    public class ProfileDataViewModel
    {
        public List<ProfileData> profiles => getProfiles();

        private List<ProfileData> getProfiles()
        {
            List<ProfileData> profiles = new List<ProfileData>()
            {
                new ProfileData() { Image = "", Name = "Susie Wright", Active = false}
            };

            return profiles;
        }
    }
}
