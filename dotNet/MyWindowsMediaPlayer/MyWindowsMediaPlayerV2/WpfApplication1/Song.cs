using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyWindowsMediaPlayerV2
{
     public class Song
     {
            #region properties
         public Song(string title, string path)
            {
                this.Title = title;
                this.Path = path;
            }

            public string Title { get; private set; }
            public string Path { get; private set; }
            #endregion
            #region utility
            public override string ToString()
            {
                return this.Title;
            }
            #endregion
     }
}
