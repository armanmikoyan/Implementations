template<typename T>
void sll<T>::print()
{
   if (!head) return;

   std::cout << std::endl;

   std::shared_ptr<Node> tmp = head;
   std::cout << "Head -> ";
   while (tmp)
   {
      if (!tmp->next)
      {
         std::cout << tmp->data << " <- Tail ";
      }
      else
      {
         std::cout << tmp->data << " -> ";
      }

      tmp = tmp->next;
   }

   std::cout << std::endl;

   tmp = tail.lock();
   std::cout << "Tail -> ";
   while (tmp)
   {
      if (!tmp->prev.lock())
      {
         std::cout << tmp->data << " <- Head ";
      }
      else
      {
         std::cout << tmp->data << " -> ";
      }

      tmp = tmp->prev.lock();
   }

   std::cout << std::endl;
   std::cout << std::endl;
}

template<typename T>
void sll<T>::push_back(const T& elem)
{
   if (!head)
   {
      head = std::make_shared<Node>(elem);
      tail = head;
      return;
   }
   if (head == tail.lock())
   {
      head->next = std::make_shared<Node>(elem);
      head->next->prev = head;
      tail = head->next;
      return;
   }

   std::shared_ptr<Node> tmp = tail.lock();
   tmp->next = std::make_shared<Node>(elem);
   tmp->next->prev = tmp;
   tail = tmp->next;
}

template<typename T>
void sll<T>::push_front(const T& elem)
{
   if (!head)
   {
      push_back(elem);
      return;
   }

   std::shared_ptr<Node> node = std::make_shared<Node>(elem);
   node->next = head;
   node->next->prev = node;
   head = node;
}

template<typename T>
void sll<T>::pop_back()
{
   if (!head) return;

   if (head == tail.lock())
   {
      head.reset();
      return;
   }

   std::shared_ptr<Node> tmp = tail.lock()->prev.lock();
   tmp->next.reset();
   tail = tmp;
}

template<typename T>
void sll<T>::pop_front()
{
   if (!head) return;

   if (head == tail.lock())
   {
      head.reset();
      return;
   }

   std::shared_ptr<Node> tmp = head->next;
   head.reset();
   head = tmp;
}

template<typename T>
void sll<T>::insert(size_t position, const T& elem)
{
   if (position == 0)
   {
      push_front(elem);
      return;
   }

   if (!head || head == tail.lock() && position != 1) return;

   std::shared_ptr<Node> tmp = head;

   while (tmp && position)
   {
      tmp = tmp->next;
      --position;
   }

   if (!tmp && position) return;

   if (!tmp && !position)
   {
      push_back(elem);
      return;
   }

   std::shared_ptr<Node> inset_after_node = tmp->prev.lock();
   inset_after_node->next = std::make_shared<Node>(elem);
   inset_after_node->next->prev = inset_after_node;
   inset_after_node->next->next = tmp;
   tmp->prev = inset_after_node->next;

}

template<typename T>
void sll<T>::erase(size_t position)
{
   if (!head) return;

   if (position == 0)
   {
      pop_front();
      return;
   }

   if (head == tail.lock()) return;

   std::shared_ptr<Node> tmp = head;

   while (tmp && position)
   {
      --position;
      tmp = tmp->next;
   }

   if (!tmp) return;
  
   if (tmp == tail.lock())
   {
      pop_back();
      return;
   }

   std::shared_ptr<Node> after = tmp->next;
   after->prev = tmp->prev;
   tmp.reset();
   after->prev.lock()->next = after;
}

