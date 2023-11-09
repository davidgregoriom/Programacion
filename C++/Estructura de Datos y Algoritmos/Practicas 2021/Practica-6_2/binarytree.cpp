

std::shared_ptr<ElementoQueue> Queue::front() const
{
    return _front;
}

void Queue::setFront(const std::shared_ptr<ElementoQueue> &front)
{
    _front = front;
}
