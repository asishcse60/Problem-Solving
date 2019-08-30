using System;
using System.Collections.Generic;
using System.Linq;

public class Friend
{
    public string Email { get; private set; }
    public static Friend TempFriend;
    public ICollection<Friend> Friends { get; private set; }
  
    public Friend(string email)
    {
        this.Email = email;
        this.Friends = new List<Friend>();
    }

    public void AddFriendship(Friend friend)
    {
        this.Friends.Add(friend);
        friend.Friends.Add(this);
    }

    public bool CanBeConnected(Friend friend)
    {
          Dictionary<string, bool> IsVisited = new Dictionary<string, bool>();
          Queue<Friend>Q = new Queue<Friend>();
        Q.Enqueue(this);

        IsVisited.Add(this.Email, true);
        while(Q.Count > 0)
        {
            var dQ = Q.Dequeue();
            if (dQ.Email == friend.Email) return true;
            foreach(var fr in dQ.Friends)
            if (IsVisited.ContainsKey(fr.Email) == false)
            {
                 IsVisited.Add(fr.Email, true);
                 Q.Enqueue(fr);
            }
        }
        return false;
    }

    public static void Main(string[] args)
    {
        Friend a = new Friend("A");
        Friend b = new Friend("B");
        Friend c = new Friend("C");

        a.AddFriendship(b);
        b.AddFriendship(c);
        Console.WriteLine(a.CanBeConnected(c));
    }
}