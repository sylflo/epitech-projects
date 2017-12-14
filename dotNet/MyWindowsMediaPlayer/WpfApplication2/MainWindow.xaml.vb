Imports System.Windows.Threading

Class MainWindow

    Private Sub Button_Click(sender As Object, e As RoutedEventArgs)
        Toto.Volume = Volume.Value / 100
        Toto.Play()
    End Sub

    Private Sub Button_Click_1(sender As Object, e As RoutedEventArgs)
        Toto.Pause()
    End Sub

    Private Sub Button_Click_2(sender As Object, e As RoutedEventArgs)
        Dim dlg = New Microsoft.Win32.OpenFileDialog()
        dlg.ShowDialog()
        Dim selFile = dlg.FileName
        If selFile.Length <> 0 Then
            Toto.Source = New Uri(selFile)
        End If
        Toto.Play()
        While Toto.NaturalDuration.HasTimeSpan = False
            System.Threading.Thread.Sleep(100)
        End While
        Progress_Time.Maximum = Toto.NaturalDuration.TimeSpan.TotalSeconds
    End Sub

    Private Sub Volume_MouseMove(sender As Object, e As MouseEventArgs)
        Toto.Volume = Volume.Value / 100
    End Sub

    Public time_hand As DispatcherTimer = New DispatcherTimer()

    Private Sub Window_Loaded(sender As Object, e As RoutedEventArgs)
        AddHandler time_hand.Tick, AddressOf dispatcherTimer_Tick
        time_hand.Interval = New TimeSpan(5000)
        time_hand.Start()
        Play_Time.Content = "00:00:00"
    End Sub

    Private Sub dispatcherTimer_Tick(ByVal sender As Object, ByVal e As EventArgs)
        Dim current_time As TimeSpan
        current_time = Toto.Position
        If current_time.ToString IsNot "00:00:00" Then
            Play_Time.Content = current_time.ToString
            Play_Time.Content = Play_Time.Content.ToString.Substring(0, Play_Time.Content.ToString.Length - 8)
        End If
        Progress_Time.Value = Toto.Position.TotalSeconds
    End Sub

    Private Sub MenuItem_Click_Open(sender As Object, e As RoutedEventArgs)
        Dim dlg = New Microsoft.Win32.OpenFileDialog()
        dlg.ShowDialog()
        Dim selFile = dlg.FileName
        If selFile.Length <> 0 Then
            Toto.Source = New Uri(selFile)
        End If
        Toto.Play()
        While Toto.NaturalDuration.HasTimeSpan = False
            System.Threading.Thread.Sleep(100)
        End While
        Progress_Time.Maximum = Toto.NaturalDuration.TimeSpan.TotalSeconds
    End Sub

    Private Sub MenuItem_Click_Close(sender As Object, e As RoutedEventArgs)
        Close()
    End Sub

    Private Sub Toto_MediaEnded(sender As Object, e As RoutedEventArgs)
        If Rep.IsChecked Then
            Toto.Position = TimeSpan.FromSeconds(0)
            Toto.Play()
        End If
    End Sub

    Private Sub Progress_Time_PreviewMouseDown(sender As Object, e As MouseButtonEventArgs)
        Toto.Pause()
        time_hand.Stop()
    End Sub

    Private Sub Progress_Time_PreviewMouseUp(sender As Object, e As MouseButtonEventArgs)
        Dim Pos As New TimeSpan(0, 0, 0, Progress_Time.Value)
        Toto.Position = Pos
        Toto.Play()
        time_hand.Start()
    End Sub
End Class