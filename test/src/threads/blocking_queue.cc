#include "./blocking_queue_mock.cc"
#include "./mutex_mock.cc"
//#include "../../../src/threads/dispatcher_middleman.h"

//#include <future>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

//using ::testing::_;
//using ::testing::InvokeWithoutArgs;
//using ::testing::Return;
using ::testing::Sequence;

class BlockingQueueTest : public ::testing::Test
{
protected:
  BlockingQueueTest()
      : my_internal_queue{new std::deque<int>()}, mtx_mock{new MutexMock()}, b_queue(my_internal_queue, mtx_mock)
  {
  }

  virtual void SetUp() { }

  void expect_locks(unsigned int num);

  std::string push_back_arg = "this string should be pushed to the back";
  std::string push_front_arg = "this string should be pushed to the front";

  //DispatcherMiddleman::CallData cData1;
  //DispatcherMiddleman::CallData cData2;
  //DispatcherMiddleman::CallData cData3;

  std::deque<int> my_internal_queue;
  std::shared_ptr<MutexMock> mtx_mock;

  BlockingQueueMock<std::deque<int>, MutexMock> b_queue;
};

// Expect the mutex to be locked and unlocked `num` times
// If lock/unlock is called in the wrong order this throws an error
// Fuerthermore, `mtx_mock` is a fake mutex which never blocks.
void BlockingQueueTest::expect_locks(unsigned int num)
{
  Sequence lock_calls;

  for(unsigned int i = 0; i < num; i++) {
    EXPECT_CALL(*mtx_mock, lock()).Times(1).InSequence(lock_calls);

    EXPECT_CALL(*mtx_mock, unlock()).Times(1).InSequence(lock_calls);
  }
}

/* TEST_F(BlockingQueueTest, TEST_FRONT)
{
  EXPECT_CALL(*my_internal_queue, front()).Times(1);
  expect_locks(1);
  auto val = b_queue.front();
}

TEST_F(BlockingQueueTest, TEST_BACK)
{
  EXPECT_CALL(*my_internal_queue, back()).Times(1);
  expect_locks(1);
  auto val = b_queue.back();
}

TEST_F(BlockingQueueTest, TEST_SIZE)
{
  EXPECT_CALL(*my_internal_queue, size()).Times(1);
  expect_locks(1);
  int qSize = b_queue.size();
}

TEST_F(BlockingQueueTest, TEST_EMPTY)
{
  EXPECT_CALL(*my_internal_queue, empty()).Times(1);
  expect_locks(1);
  bool res = b_queue.empty();
}

TEST_F(BlockingQueueTest, TEST_CLEAR)
{
  EXPECT_CALL(*my_internal_queue, clear()).Times(1);
  expect_locks(1);
  b_queue.clear();
}

TEST_F(BlockingQueueTest, TEST_PUSH)
{
  EXPECT_CALL(*my_internal_queue, push_back(cData3)).Times(1);
  expect_locks(1);
  b_queue.push(cData3);
}

TEST_F(BlockingQueueTest, TEST_PUSH_FRONT)
{
  EXPECT_CALL(*my_internal_queue, push_front(cData3)).Times(1);
  expect_locks(1);
  b_queue.push_front(cData3);
}

TEST_F(BlockingQueueTest, TEST_POP)
{
  EXPECT_CALL(*my_internal_queue, pop()).Times(1);
  expect_locks(1);
  b_queue.pop();
}*/
