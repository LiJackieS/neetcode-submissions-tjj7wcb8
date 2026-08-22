struct Stock {
    int price;
    int span;

    Stock(int price, int span) : price(price), span(span) {}
};

class StockSpanner {
public:
    std::stack<Stock> stocks;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!stocks.empty() && stocks.top().price <= price) {
            span += stocks.top().span;
            stocks.pop();
        }
        stocks.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */