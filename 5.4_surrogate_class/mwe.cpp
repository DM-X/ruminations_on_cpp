#include <iostream>

using std::cout;
using std::endl;

class Parent_a
{
   public:
      Parent_a(): a(1) { }
      void set_a(int a_v) {a = a_v;}
      int  get_a() {return a;}
      virtual int get_b() {}
      virtual int get_c() {}
   private:
      int a;
};

class Child_b: public Parent_a
{
   public:
      Child_b(): b(2) { }
      void set_b(int b_v) {b = b_v;}
      int  get_b() {return b;}
   private:
      int b;
};

class Child_c: public Child_b
{
   public:
      Child_c(): c(3) { }
      void set_c(int c_v) {c = c_v;}
      int  get_c() {return c;}
   private:
      int c;
};


int main()
{
   Parent_a pa;
   Child_b  cb;

   cout << "Parent_a.a: " << pa.get_a() << endl;
   cout << "Child_b.b:  " << cb.get_b() << endl;

   cout << "Child_b.a:  " << cb.get_a() << endl;

   Parent_a* p_pa_b = &cb;
   cout << "p_pa_b->b:  " << p_pa_b->get_b() << endl; //needs virtual get_b() decl. in Parent a

   Child_c cc;
   Parent_a* p_pa_c = &cc;
   cout << "p_pa_c->b:  " << p_pa_c->get_b() << endl;
   cout << "p_pa_c->c:  " << p_pa_c->get_c() << endl; //needs virtual get_c() decl. in Parent a
   Child_b* p_pb_c = &cc;
   cout << "p_pb_c->c:  " << p_pb_c->get_c() << endl; //does NOT need virtual get_c() decl. in Child_b because Child_b inherits virtual get_c() from Parent_a 

   cout << "p_pa_b->c:  " << p_pa_b->get_c() << endl; //garbadge result

   return 0;
}
